#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

#include "TextData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class rigBuilderModel : public NodeDataModel
{
	Q_OBJECT

public:
	rigBuilderModel();

	virtual
		~rigBuilderModel() {}

public:

	QStringList bipedRig =
	{
		"Control",
		"Hand_L",
		"Hand_R",
		"Spine",
		"Neck",
		"Leg_L",
		"Leg_R",
		"Arm_L",
		"Arm_R"
	};

	QString
		caption() const override
	{
		return QString("Text Display");
	}

	bool
		captionVisible() const override { return false; }

	bool
		portCaptionVisible(PortType, PortIndex) const override
	{
		return true;
	}

	static QString
		Name()
	{
		return QString("rigBuilderModel");
	}

	QString
		name() const override
	{
		return rigBuilderModel::Name();
	}

	QString
		portCaption(PortType portType, PortIndex portIndex) const override;

public:

	unsigned int
		nPorts(PortType portType) const override;

	NodeDataType
		dataType(PortType portType, PortIndex portIndex) const override;

	std::shared_ptr<NodeData>
		outData(PortIndex port) override;

	QStringList msg;

	void
		setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) override
	{
		auto textData = std::dynamic_pointer_cast<TextData>(data);

		QString inData;
		if (textData)
		{
			msg[portIndex] = textData->text();
			for (auto i : msg)
			{
				inData += i+"\r\n";
			}
			_label->setText(inData);
		}
		else
		{
			msg[portIndex] = "";
			for (auto i : msg)
			{
				inData += i + "\r\n";
			}
			_label->setText(inData);
		}

		_label->adjustSize();
	}

	QWidget *
		embeddedWidget() override { return _label; }

private slots:

	void
		onTextChanged();

private:

	QTextEdit * _label;
};


