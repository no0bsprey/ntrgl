#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QSettings>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent, QSettings *config);
    void setTopPixmap(QPixmap pixmap);
    void setBotPixmap(QPixmap pixmap);

signals:
    void Resize(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap topPixmap;
    QPixmap botPixmap;
    QSettings *config;
    int x, y;
    bool topInited, botInited;
};

#endif // GLWIDGET_H
