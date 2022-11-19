#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWidget>
#include "glwidget.h"

class GLWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GLWindow(QSettings *config, QWidget *parent = nullptr);
public slots:
    void setTopPixmap(QPixmap pixmap);
    void setBotPixmap(QPixmap pixmap);
    void setSize(int x, int y);

private:
    GLWidget *glWidget;
    bool isInited;
};

#endif // GLWINDOW_H
