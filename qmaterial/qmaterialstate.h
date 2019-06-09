#ifndef QMATERIALSTATE_H
#define QMATERIALSTATE_H

#include <QStateMachine>

//!
//! \brief The QMaterialState class
//! https://material.io/design/interaction/states.html#usage
//!
class QMaterialState : public QStateMachine
{
public:
    QMaterialState();


private:
    QState m_enabled;
    QState m_disabled;
    QState m_hover;
    QState m_focused;
    QState m_selected;
    QState m_activated;
    QState m_pressed;
    QState m_dragged;
    QState m_on;
    QState m_off;
    QState m_error;
};

#endif // QMATERIALSTATE_H
