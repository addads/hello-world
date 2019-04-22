#include "window.h"


void Window::mousePressEvent(QMouseEvent *event)
{


    if(event->buttons() == Qt::RightButton)
    {
        if(!m_clicked)
        {
            m_clicked = !m_clicked;
            m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));
            m_button->setStyleSheet(("background-color:blue"));
        }
        else
        {
            m_button->setStyleSheet((""));
            m_clicked = !m_clicked;
            m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));
        }
    }
}

void Window::setColors()
{

   if(!m_clicked)
   {
       m_clicked = !m_clicked;
       m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));
       m_button->setStyleSheet(("background-color:red"));
   }
   else
   {
        m_button->setStyleSheet((""));
        m_clicked = !m_clicked;
        m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));
    }

}

void Window::hoverColor()
{
        m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));
}

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 150);
    m_button = new QPushButton("Click here for unicorns.", this);
    m_button->setGeometry(10, 10, 280, 30);
    m_button->setToolTip("Or not");

    QFont font("Georgia");
    m_button->setFont(font);
    m_button->setStyleSheet(("QPushButton:hover { background-color: yellow}"));

    m_clicked = false;

    connect(m_button, SIGNAL(clicked()), this, SLOT(setColors()));

    QIcon icon("C:/Users/ACalota/Desktop/Afternoon-Delight-Unicorn-Rainbow-Sex.jpg");
    m_button->setIcon(icon);

    m_quit_button = new QPushButton("Exit", this);
    m_quit_button->setGeometry(10, 110, 280, 30);
    m_quit_button->setToolTip("Kill me");

    connect(m_quit_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));



    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(40, 50, 250, 30);


    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 80, 280, 30);

    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
}
