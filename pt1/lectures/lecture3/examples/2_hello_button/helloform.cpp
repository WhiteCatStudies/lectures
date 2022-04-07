#include "helloform.h"

#include <QString>

#include <iostream>


HelloForm::HelloForm(QWidget* parent):
	QWidget(parent)
{
	_ui.setupUi(this);
	
	QObject::connect(_ui.helloButton, SIGNAL(clicked()), 
		this, SLOT(_onButtonClicked()));

	int offset = 0;
	_displayObjectName(this, offset);
	_displayObjectTree(this, ++offset);
}

void HelloForm::_onButtonClicked()
{
	const QString name = _ui.nameEdit->text();
	if(name.isEmpty())
	{
		return;	
	};

	_ui.helloLabel->setText(QString("Hello, ") + name + "!");
}

void HelloForm::_displayObjectTree(const QObject* obj, int& offset) const
{
	if(obj == nullptr)
	{
		return;
	}

	const auto childList = obj->children();
	for(const auto* obj: childList)
	{
		_displayObjectName(obj, offset);
		_displayObjectTree(obj, ++offset);
		--offset;
	}
}

void HelloForm::_displayObjectName(const QObject* obj, int& offset) const
{
	_ui.treeDisplayLabel->setText(_ui.treeDisplayLabel->text() + "\n" + 
		QString(offset * 4, QChar(' ')) + obj->objectName());
}