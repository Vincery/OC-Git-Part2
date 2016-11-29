#include "MaFenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(280, 100);

    m_progressbar=new QProgressBar(this);
    m_progressbar->setGeometry(10, 20, 180, 20);
    m_progressbar->setMinimum(280);
    m_progressbar->setMaximum(800);

    m_slider=new QSlider(Qt::Horizontal,this);
    m_slider->setRange(280,800);
    m_slider->setGeometry(10, 60, 150, 20);

    m_pushbutton=new QPushButton("Reset", this);
    m_pushbutton->setGeometry(190, 20, 80, 60);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)),this, SLOT(ChangerLargeurFenetre(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_progressbar, SLOT(setValue(int)));
    QObject::connect(m_pushbutton, SIGNAL(clicked()), m_progressbar, SLOT(reset()));
    QObject::connect(m_pushbutton, SIGNAL(clicked()), this, SLOT(ResetSlider()));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(aboutQt()));
}

void MaFenetre::ResetSlider()
{
    m_slider->setValue(0);
}

void MaFenetre::ChangerLargeurFenetre(int largeur)
{
    setFixedSize(largeur,100);

    if (largeur==800)
    {
        emit agrandissementMax();
    }
}
