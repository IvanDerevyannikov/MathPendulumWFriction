#include "PendView.h"





void PendView::moveTimer() {
	static int i = 0;
	//qDebug() << ++i;
	rect->setRotation((360));
}


PendView::PendView(QWidget* parent):QGraphicsView(parent)
{
	scene = new QGraphicsScene(0, 0, 800, 800, this);

	pend = new MathPendulum;
	pend->setPos(400, 400);
	pend->setRotation(-40);

	scene->addItem(pend);



	rect = new QGraphicsRectItem(0, 0, scene->width(), scene->height());
	scene->addItem(rect);

	this->setScene(scene);


	pendTimer = new QTimer(this);

	connect(pendTimer, SIGNAL(timeout()), scene, SLOT(advance()));
	connect(pendTimer, SIGNAL(timeout()),this,SLOT(moveTimer()));

}




void PendView::startSim() {
	pendTimer->start(1);
	pend->tt = 0;
}


void PendView::stopSim() {
	pendTimer->stop();
}


void PendView::setPendPos(int angle) {
	pend->setRotation((angle/10.-180));
	pend->setAngle((angle/10.-180));
	scene->update();
}


void PendView::setPendSpeed(int speed) {

	pend->setSpeed(speed / 10.);
}


void PendView::setPendMass(int mass) {
	pend->setMass(mass);
}


void PendView::setPendBetta(int betta) {
	pend->setBetta(betta / 1000.);
}


void PendView::setPendOmega(int omega) {
	pend->setOmega(omega / 100.);
}


void PendView::setPendAmplitude(int ampl) {
	pend->setAmplitude(ampl/10.);
}







MathPendulum::MathPendulum(QGraphicsItem* parent): QGraphicsItem(parent)
{
	speed = 0;
	tt = 0;

}


void MathPendulum::setAngle(int angle) {
	this->angle = angle;
}


void MathPendulum::setSpeed(double speed) {
	this->speed = speed;
}


void  MathPendulum::setMass(double mass) {
	this->mass = mass;
	
}


void  MathPendulum::setBetta(double betta) {
	this->betta = betta;
	
}


void  MathPendulum::setOmega(double omega) {
	this->omega = omega;
	
}


void  MathPendulum::setAmplitude(double ampl) {
	this->amplitude = ampl;
	
}


QRectF MathPendulum::boundingRect() const
{
	return QRectF();
}


void MathPendulum::paint(QPainter* painter,
	const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setBrush(Qt::green);
	painter->setPen(QPen(Qt::black, 5));
	painter->drawLine(00, 00, 00, 250);
	painter->setBrush(Qt::red);
	painter->drawEllipse(-20, 250, 40, 40);
}


void MathPendulum::advance(int phase)
{
	static int i = 0;
	if (!phase) return;

	qreal loc = this->rotation();
	RungeKutta(i, loc, speed);
	setRotation(loc);
	++i;
	//() <<loc << ' ' << sin(loc);
	//qDebug() << loc;
}


void MathPendulum::Rotate(qreal angle)
{
	this->setRotation(angle);
}


void MathPendulum::RungeKutta(qreal t,qreal& angle,qreal& speed)
{
	double tetta = 0.01;
	QVector<double> K;
	QVector<double> Q;

	K.push_back(speed);
	Q.push_back(U(tt, angle, speed));
	K.push_back(speed + (Q[0] * tetta / 2));
	Q.push_back(U(tt + (tetta / 2), angle + (K[0] * tetta / 2), speed * (Q[0] * tetta / 2)));
	K.push_back(speed + (Q[1] * tetta / 2));
	Q.push_back(U(tt + (tetta / 2), angle + (K[1] * tetta / 2), speed * (Q[1] * tetta / 2)));
	K.push_back(speed + (Q[2] * tetta));
	Q.push_back(U(tt + (tetta), angle + (K[2] * tetta), speed * (Q[2] * tetta)));

	speed = speed + tetta/6* (Q[0]+2*Q[1]+2*Q[2]+Q[3]);
	angle = angle + tetta / 6 * (K[0] + 2 * K[1] + 2 * K[2] + K[3]);
	
	if (angle < -180) angle += 360;
	if (angle > 180) angle -= 360;

	tt += tetta;
	qDebug() << angle << ' ' << speed;
}