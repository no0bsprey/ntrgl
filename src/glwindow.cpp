#include <QGridLayout>
#include <QTimer>

#include "glwindow.h"

GLWindow::GLWindow(QSettings *config, QWidget *parent)
    : QWidget{parent}
{
        QGridLayout *layout = new QGridLayout(this);
        glWidget = new GLWidget(this, config);
        layout->addWidget(glWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        connect(glWidget, SIGNAL(Resize(int,int)), this, SLOT(setSize(int,int)));
}

void GLWindow::setTopPixmap(QPixmap pixmap)
{
    glWidget->setTopPixmap(pixmap);
}

void GLWindow::setBotPixmap(QPixmap pixmap)
{
    glWidget->setBotPixmap(pixmap);
}

void GLWindow::setSize(int x, int y)
{
    setMinimumSize(x, y);
    setMaximumSize(x, y);
    resize(x, y);
    activateWindow();
}
