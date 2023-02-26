#pragma once
#include "PendView.h"
#include <QWidget>
#include <QHBoxLayout>
#include<QPushButton>
#include <QGridLayout>
#include <QSlider>
#include <QLineEdit>
#include <QLabel> 
#include "qcustomplot.h"


class Mainwindow : public QWidget {
	Q_OBJECT
public:
	Mainwindow(QWidget* parent = 0);
	//~Mainwindow();

public slots:
	

private:

	PendView* scene;
	QPushButton* start;
	QPushButton* stop;


	QSlider* mass;
	QSlider* betta;
	QSlider* omega;
	QSlider* initPos;
	QSlider* initSpeed;
	QSlider* amplitude;

	QLineEdit* massEd;
	QLineEdit* bettaEd;
	QLineEdit* omegaEd;
	QLineEdit* initPosEd;
	QLineEdit* initSpeedEd;
	QLineEdit* amplitudeEd;


	QLabel* massLbl;
	QLabel* bettaLbl;
	QLabel* omegaLbl;
	QLabel* initPosLbl;
	QLabel* initSpeedLbl;
	QLabel* amplitudeLbl;


	double f(double t) {

		return amplitude->value() * sin((omega->value()/10.) * t);
	}

	double U(double t, double angle, double speed) {
		double ans = f(t) / mass->value() - sin(angle * M_PI / 180) - (betta->value()/1000.) / mass->value() * speed;
		return ans;
	}

};