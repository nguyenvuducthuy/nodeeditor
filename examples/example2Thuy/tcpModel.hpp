#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include "tcp.hpp"

#include "TextData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class tcpModel : public NodeDataModel
{
	Q_OBJECT

public:
	tcpModel();

	virtual
		~tcpModel() {}

public:

	QString
		caption() const override
	{
		return QString("Text Display");
	}

	bool
		captionVisible() const override { return false; }

	static QString
		Name()
	{
		return QString("tcpModel");
	}

	QString
		name() const override
	{
		return tcpModel::Name();
	}

public:

	unsigned int
		nPorts(PortType portType) const override;

	NodeDataType
		dataType(PortType portType, PortIndex portIndex) const override;

	std::shared_ptr<NodeData>
		outData(PortIndex port) override;

	MyTcpServer thuy;

	void
		setInData(std::shared_ptr<NodeData> data, int) override
	{
		auto textData = std::dynamic_pointer_cast<TextData>(data);

		if (textData)
		{
			_label->setText(textData->text());
			thuy.setMsg(textData->text());
		}
		else
		{
			_label->clear();
		}

		_label->adjustSize();
	}

	QWidget *
		embeddedWidget() override { return _label; }

private:

	QLabel * _label;
};


