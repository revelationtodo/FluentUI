#pragma once

#include "../FluUtils/FluUtils.h"
#include <QPushButton>
#include "FluWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QStyleOption>
#include <QPainter>

#include "FluTimePicker24HView.h"

class FluTimePicker24H : public FluWidget
{
    Q_OBJECT
  public:
    FluTimePicker24H(bool withSecond = false, QWidget* parent = nullptr);

    void mouseReleaseEvent(QMouseEvent* event);

    void paintEvent(QPaintEvent* event);

    QTime getCurTime();
    void setCurTime(QTime time);

  signals:
    void clicked();
    void selectedTime(QTime time);

  public slots:
    void onThemeChanged();

  protected:
    QHBoxLayout* m_hMainLayout;
    QPushButton* m_hourBtn;
    QPushButton* m_minuteBtn;
    QPushButton* m_secondBtn;

    FluTimePicker24HView* m_timerPicker24HView;

    bool m_withSecond;
};
