#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include<QDebug>
#include <QGraphicsItemAnimation>
#include<QVector>

# define M_PI           3.14159265358979323846



class MathPendulum : public QGraphicsItem {
	//Q_OBJECT
public:

	MathPendulum(QGraphicsItem* parent = 0);

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

	void advance(int phase) override;

	void Rotate(qreal angle);

	void RungeKutta(qreal t,qreal& angle, qreal& speed);

	void setAngle(int angle);
	void setSpeed(double speed);
	void setMass(double mass);
	void setBetta(double betta);
	void setOmega(double omega);
	void setAmplitude(double ampl);


	double tt;
private:

	double speed;
	int angle;
	double omega;
	double mass;
	double amplitude;
	double betta;


	double f(double t) {
		return amplitude * sin(omega * t);
	}


	double U(double t, double angle, double speed) {
		double ans =  f(t)/mass - sin(angle * M_PI / 180) -  betta/mass* speed;
		return ans;
	}



};


class PendView : public QGraphicsView {
	Q_OBJECT
public:

	PendView(QWidget* parent = 0);

private:
	QGraphicsScene* scene;
	MathPendulum* pend;
	QTimer* pendTimer;
	QGraphicsRectItem* rect;


private slots:
	void moveTimer();

public slots:
	void startSim();
	void stopSim();

	void setPendPos(int angle);
	void setPendSpeed(int speed);

	void setPendMass(int mass);
	void setPendBetta(int betta);
	void setPendOmega(int omega);
	void setPendAmplitude(int ampl);

};