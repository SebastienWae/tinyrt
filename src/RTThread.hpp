#ifndef RTTHREAD_HPP
#define RTTHREAD_HPP

#include <QThread>

class RTThread : public QThread {
  Q_OBJECT
public:
  RTThread();
  void run() override;
  void render();

signals:
  void renderedRT(const QImage &image);
};

#endif // RTTHREAD_HPP
