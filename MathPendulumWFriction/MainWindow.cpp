#include "MainWindow.h"

Mainwindow::Mainwindow(QWidget* parent) :QWidget(parent) {

	QGridLayout* lay = new QGridLayout(this);
	scene = new PendView;
	lay->addWidget(scene,3,0,1,6);


	start = new QPushButton("Start", this);
	stop = new QPushButton("Stop", this);

	mass = new QSlider(Qt::Horizontal,this);
	betta = new QSlider(Qt::Horizontal, this);
	omega = new QSlider(Qt::Horizontal, this);
	initPos = new QSlider(Qt::Horizontal, this);
	initSpeed = new QSlider(Qt::Horizontal, this);
	amplitude = new QSlider(Qt::Horizontal, this);

	betta->setMinimum(0);
	betta->setMaximum(1000);

	initPos->setMinimum(0);
	initPos->setMaximum(3600);

	initSpeed->setMinimum(-100);
	initSpeed->setMaximum(100);

	mass->setMinimum(1);
	mass->setMaximum(10);

	omega->setMaximum(1000);

	amplitude->setMaximum(100);


	lay->addWidget(mass, 1, 0, 1, 1);
	lay->addWidget(betta, 1, 1, 1, 1);
	lay->addWidget(amplitude, 1, 2, 1, 1);
	lay->addWidget(omega, 1, 3, 1, 1);
	lay->addWidget(initPos, 1, 4, 1, 1);
	lay->addWidget(initSpeed, 1, 5, 1, 1);


	massEd = new QLineEdit(this);
	bettaEd = new QLineEdit(this);
	omegaEd = new QLineEdit(this);
	initPosEd = new QLineEdit(this);
	initSpeedEd = new QLineEdit(this);
	amplitudeEd = new QLineEdit(this);


	connect(mass, &QSlider::valueChanged, this, [=]() {
		massEd->setText(QString::number(mass->value())); });
	connect(betta, &QSlider::valueChanged, this, [=]() {
		bettaEd->setText(QString::number(betta->value()/1000.0)); });
	connect(omega, &QSlider::valueChanged, this, [=]() {
		omegaEd->setText(QString::number(omega->value()/100.)); });
	connect(initPos, &QSlider::valueChanged, this, [=]() {
		initPosEd->setText(QString::number(initPos->value()/10. -180)); });
	connect(initSpeed, &QSlider::valueChanged, this, [=]() {
		initSpeedEd->setText(QString::number(initSpeed->value()/10.)); });
	connect(amplitude, &QSlider::valueChanged, this, [=]() {
		amplitudeEd->setText(QString::number(amplitude->value()/10.)); });


	lay->addWidget(massEd, 2, 0, 1, 1);
	lay->addWidget(bettaEd, 2, 1, 1, 1);
	lay->addWidget(amplitudeEd, 2, 2, 1, 1);
	lay->addWidget(omegaEd, 2, 3, 1, 1);
	lay->addWidget(initPosEd, 2, 4, 1, 1);
	lay->addWidget(initSpeedEd, 2, 5, 1, 1);



	massLbl=new QLabel("mass",this);
	bettaLbl = new QLabel("betta", this);
	omegaLbl = new QLabel("omega", this);
	initPosLbl = new QLabel("initPos", this);
	initSpeedLbl = new QLabel("initSpeed", this);
	amplitudeLbl = new QLabel("amplitude", this);

	lay->addWidget(massLbl, 0, 0, 1, 1);
	lay->addWidget(bettaLbl, 0, 1, 1, 1);
	lay->addWidget(amplitudeLbl, 0, 2, 1, 1);
	lay->addWidget(omegaLbl, 0, 3, 1, 1);
	lay->addWidget(initPosLbl, 0, 4, 1, 1);
	lay->addWidget(initSpeedLbl, 0, 5, 1, 1);





	lay->addWidget(start,4,0,1,3);
	lay->addWidget(stop,4,3,1,3);
	setLayout(lay);

	connect(start, SIGNAL(clicked()), scene, SLOT(startSim()));
	connect(stop, SIGNAL(clicked()), scene, SLOT(stopSim()));



	connect(mass, SIGNAL(valueChanged(int)), scene, SLOT(setPendMass(int)));
	connect(betta, SIGNAL(valueChanged(int)), scene, SLOT(setPendBetta(int)));
	connect(amplitude, SIGNAL(valueChanged(int)), scene, SLOT(setPendAmplitude(int)));
	connect(omega, SIGNAL(valueChanged(int)), scene, SLOT(setPendOmega(int)));
	connect(initPos, SIGNAL(valueChanged(int)), scene, SLOT(setPendPos(int)));
	connect(initSpeed, SIGNAL(valueChanged(int)), scene, SLOT(setPendSpeed(int)));

}


