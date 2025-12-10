#pragma once

#include "FluWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QStyleOption>

#include "../FluUtils/FluUtils.h"
#include "FluCalendarTimeView.h"

class FluCalendarDateTimePicker : public QPushButton
{
    Q_OBJECT
  public:
    FluCalendarDateTimePicker(QWidget* parent = nullptr)
        : QPushButton(parent)
    {
        m_hMainLayout = new QHBoxLayout;
        m_textButton  = new QPushButton;
        m_iconButton  = new QPushButton;

        m_textButton->setObjectName("textButton");
        m_iconButton->setObjectName("iconButton");

        setLayout(m_hMainLayout);

        setMinimumHeight(20);

        m_textButton->setText("Pick a date");

        m_iconButton->setIconSize(QSize(20, 20));
        m_iconButton->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Calendar));
        m_iconButton->setFixedWidth(30);

        m_hMainLayout->setContentsMargins(0, 0, 0, 0);
        m_hMainLayout->addWidget(m_textButton);
        m_hMainLayout->addWidget(m_iconButton);

        m_calendarView = new FluCalendarTimeView(window());
        m_calendarView->setWindowFlag(Qt::Popup);

        connect(m_calendarView, &FluCalendarTimeView::selectedDate, [=](QDate date) {
            QString dateText = QString::asprintf("%d/%d/%d", date.month(), date.day(), date.year());
            m_textButton->setText(dateText);
            // LOG_DEBUG << date;
            m_calendarView->hide();

            emit selectedDate(date);
        });

        connect(m_calendarView, &FluCalendarTimeView::selectedTime, [=](QTime time) {
            emit selectedTime(time);
        });

        connect(this, &FluCalendarDateTimePicker::clicked, [=]() { onClicked(); });
        connect(m_textButton, &QPushButton::clicked, [=]() { onClicked(); });
        connect(m_iconButton, &QPushButton::clicked, [=]() { onClicked(); });

        FluStyleSheetUitls::setQssByFileName("FluCalendarDateTimePicker.qss", this, FluThemeUtils::getUtils()->getTheme());
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
        //  {
        //     onThemeChanged();
        // });
    }

    void reset()
    {
        setCurDate(QDate::currentDate());
        m_textButton->setText("Pick a date");
    }

    QDate getCurDate()
    {
        return m_calendarView->getCurDate();
    }

    void setCurDate(QDate date)
    {
        m_calendarView->setCurDate(date);

        emit m_calendarView->selectedDate(date);
    }

    QTime getCurTime()
    {
        m_calendarView->getCurTime();
    }

    void setCurTime(QTime time)
    {
        m_calendarView->setCurTime(time);

        emit m_calendarView->selectedTime(time);
    }

  signals:
    void selectedDate(QDate date);
    void selectedTime(QTime time);

  public slots:
    void onClicked()
    {
        // LOG_DEBUG << "clicked!";
        //  if (!m_calendarView->isHidden())
        //  {
        //      m_calendarView->hide();
        //       return;
        //   }

        // the pos
        int nX = width() / 2;
        int nY = height() + 5;

        // LOG_DEBUG << "nX:" << nX << ",nY:" << nY;
        // LOG_DEBUG << m_calendarView->width();
        QPoint gPoint = mapToGlobal(QPoint(nX, nY));
        // LOG_DEBUG << gPoint;
        m_calendarView->move(gPoint.x() - m_calendarView->width() / 2, gPoint.y());
        m_calendarView->show();
    }

    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            m_iconButton->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Calendar));
            FluStyleSheetUitls::setQssByFileName("FluCalendarDateTimePicker.qss", this, FluThemeUtils::getUtils()->getTheme());
        }
        else
        {
            m_iconButton->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Calendar, FluTheme::Dark));
            FluStyleSheetUitls::setQssByFileName("FluCalendarDateTimePicker.qss", this, FluThemeUtils::getUtils()->getTheme());
        }
    }

  protected:
    QHBoxLayout* m_hMainLayout;
    QPushButton* m_textButton;
    QPushButton* m_iconButton;

    FluCalendarTimeView* m_calendarView;
};
