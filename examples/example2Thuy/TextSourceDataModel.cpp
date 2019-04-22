#include "TextSourceDataModel.hpp"

TextSourceDataModel::
TextSourceDataModel()
  : _lineEdit(new QTextEdit("Default Text"))
{
  connect(_lineEdit, &QTextEdit::textChanged,
          this, &TextSourceDataModel::onTextChanged);
}


unsigned int
TextSourceDataModel::
nPorts(PortType portType) const
{
  unsigned int result = 1;

  switch (portType)
  {
    case PortType::In:
      result = 0;
      break;

    case PortType::Out:
      result = 1;

    default:
      break;
  }

  return result;
}


void
TextSourceDataModel::
//onTextEdited(QString const &string)
onTextChanged()
{
  //Q_UNUSED(string);

  emit dataUpdated(0);
}


NodeDataType
TextSourceDataModel::
dataType(PortType, PortIndex) const
{
  return TextData().type();
}


std::shared_ptr<NodeData>
TextSourceDataModel::
outData(PortIndex)
{
  return std::make_shared<TextData>(_lineEdit->toPlainText());
}
