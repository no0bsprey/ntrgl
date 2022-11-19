#include <QPainter>
#include <stdlib.h>
#include "glwidget.h"

namespace
{
const char*  CFG_TSCALE = "topScale";
const double DEF_TSCALE = 1;
const char*  CFG_BSCALE = "botScale";
const double DEF_BSCALE = 1;
}

GLWidget::GLWidget(QWidget *parent, QSettings *settings) : QOpenGLWidget(parent), topInited(false), botInited(false)
{
    setAutoFillBackground(true);
    config = settings;
    setMinimumSize(192, 168);
}

void GLWidget::setTopPixmap(QPixmap pixmap)
{
    this->topPixmap = pixmap;
    if (!topInited)
    {
        topInited = true;
    }
    update();
}

void GLWidget::setBotPixmap(QPixmap pixmap)
{
    this->botPixmap = pixmap;
    if (!botInited)
    {
        botInited = true;
    }
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    if (!topInited || !botInited)
    {
        return;
    }

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    float topScale = config->value(CFG_TSCALE, DEF_TSCALE).toFloat();
    QTransform topForm(0, -topScale, topScale, 0, 0, 0);
    QPixmap top = topPixmap.transformed(topForm);
    painter.drawPixmap(0, 0, top);
    float botScale = config->value(CFG_BSCALE, DEF_BSCALE).toFloat();
    QTransform botForm(0, -botScale, botScale, 0, 0, 0);
    QPixmap bot = botPixmap.transformed(botForm);
    painter.drawPixmap((top.width() / 2) - (bot.width() / 2), top.height(), bot);
    painter.end();

    int newX = fmax(top.width(), bot.width());
    int newY = top.height() + bot.height();

    if (newX != x || newY != y)
    {
        x = newX;
        y = newY;
        emit Resize(x, y);
    }
}
