#include "rigBuilderModel.hpp"

rigBuilderModel::
rigBuilderModel()
	: _label(new QLabel("Resulting Text"))
{
	_label->setMargin(3);
}


unsigned int
rigBuilderModel::
nPorts(PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case PortType::In:
		result = 2;
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
	std::shared_ptr<NodeData> ptr;
	return ptr;
}

QString
rigBuilderModel::
portCaption(PortType portType, PortIndex portIndex) const
{
	switch (portType)
	{
	case PortType::In:
		for (int i = 0; i< bipedRig->length(); i++)
		{
			if (portIndex == i)
				return QStringLiteral(bipedRig[i]);
		}

		break;

	case PortType::Out:
		return QStringLiteral("Result");

	default:
		break;
	}
	return QString();
}