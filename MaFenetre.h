#ifndef MAFENETRE
#define MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

class MaFenetre : public QWidget
{
    Q_OBJECT

private:
    QProgressBar *m_progressbar;
    QSlider *m_slider;
    QPushButton *m_pushbutton;

public:
    MaFenetre();

signals:
    void agrandissementMax();

public slots:
    void ResetSlider();
    void ChangerLargeurFenetre (int largeur);
};

#endif