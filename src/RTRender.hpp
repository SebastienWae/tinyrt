#ifndef RTRENDER_HPP
#define RTRENDER_HPP

#include <QPainter>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "RTThread.hpp"

class RTRender : public QQuickPaintedItem {
  Q_OBJECT
  QML_ELEMENT
public:
  RTRender();
  ~RTRender();

  void paint(QPainter *painter);

private slots:
  void updatePixmap(const QImage &image);

private:
  QPixmap m_pixmap;
  RTThread m_thread;
};

#endif // RTRENDER_HPP
