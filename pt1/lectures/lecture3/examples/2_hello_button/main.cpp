#include <QApplication>

#include "helloform.h"


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	HelloForm helloForm;
	helloForm.show();
	
	return app.exec();
}