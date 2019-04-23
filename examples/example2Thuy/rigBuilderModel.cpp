#include "rigBuilderModel.hpp"

rigBuilderModel::
rigBuilderModel()
	: _label(new QTextEdit("Resulting Text"))
{
	//_label->setMargin(3);
	connect(_label, &QTextEdit::textChanged,
		this, &rigBuilderModel::onTextChanged);

	for (int i = 0; i < bipedRig.length(); i++)
	{
		msg.append("");
	}
}


unsigned int
rigBuilderModel::
nPorts(PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case PortType::In:
		result = bipedRig.length();
		break;

	case PortType::Out:
		result = 1;

	default:
		break;
	}

	return result;
}


NodeDataType
rigBuilderModel::
dataType(PortType, PortIndex) const
{
	return TextData().type();
}


std::shared_ptr<NodeData>
rigBuilderModel::
outData(PortIndex)
{
	return std::make_shared<TextData>(_label->toPlainText());
}

QString
rigBuilderModel::
portCaption(PortType portType, PortIndex portIndex) const
{
	switch (portType)
	{
	case PortType::In:
		for (int i = 0; i< bipedRig.length(); i++)
		{
			if (portIndex == i)
				//return QStringLiteral(bipedRig[i]);
				return bipedRig[i];
		}

		break;

	case PortType::Out:
		return QStringLiteral("Result");

	default:
		break;
	}
	return QString();
}

void
rigBuilderModel::
onTextChanged()
{
	emit dataUpdated(0);
}
