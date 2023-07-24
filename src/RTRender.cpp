#include "RTRender.hpp"
#include "RTThread.hpp"

RTRender::RTRender() {
  connect(&m_thread, &RTThread::renderedRT, this, &RTRender::updatePixmap);
  m_thread.start();
}

RTRender::~RTRender() {
  m_thread.quit();
  m_thread.wait();
}

void RTRender::paint(QPainter *painter) {
  if (!m_pixmap.isNull()) {
    painter->drawPixmap(0, 0, width(), height(), m_pixmap);
  }
}

void RTRender::updatePixmap(const QImage &image) {
  m_pixmap = QPixmap::fromImage(image);
  update();
}
