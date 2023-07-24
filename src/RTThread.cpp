#include <QImage>

#include "RTThread.hpp"

RTThread::RTThread() {}

void RTThread::render() {}

void RTThread::run() {
  QImage image{QSize{100, 100}, QImage::Format_ARGB32};

  long x = 0;
  long y = 0;

  for (long y = 0; y < image.height(); y++) {
    for (long x = 0; x < image.width(); x++) {
      QRgb *line = reinterpret_cast<QRgb *>(image.scanLine(y));
      QRgb &rgb = line[x];
      rgb = QColor("red").rgb();
      emit renderedRT(image);
      usleep(500);
    }
  }
}
