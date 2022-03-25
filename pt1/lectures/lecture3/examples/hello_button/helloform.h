#pragma once

#include "ui_helloform.h"


// Если бы класс HelloForm должен был быть одновременно частью другой иерархии,
// класс QObject (или другой класс, угаследованный от QObject)
// должен был бы стоять первым:
// class HelloForm : public QWidget, public SomeOtherClass { ...
// При этом от QObject должен наследоваться только один из базовых классов
class HelloForm : public QWidget
{
	Q_OBJECT

public:
	HelloForm(QWidget* parent = nullptr);

private slots:
	void _onButtonClicked();


private:
	Ui::HelloForm _ui;

	void _displayObjectTree(const QObject* obj, int& offset) const;
	void _displayObjectName(const QObject* obj, int& offset) const;

};