// MathPendulumWFriction.cpp: определяет точку входа для приложения.
//

#include "MathPendulumWFriction.h"
#include <QApplication>
#include <QWidget>
#include "qcustomplot.h"
#include <QVector>
#include "MainWindow.h"


//using namespace std;


int main(int argc, char* argv[]) 
{
	QApplication app(argc, argv);
	Mainwindow wind;
	wind.resize(1500, 900);


	wind.show();


	return app.exec();

}
