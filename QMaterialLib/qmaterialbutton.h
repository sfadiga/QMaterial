#ifndef QMATERIALBUTTON_H
#define QMATERIALBUTTON_H

#include <QPushButton>
#include <QState>

#include "qmaterialstate.h"
#include "qmaterialoverlay.h"
#include "qmaterialtheme.h"
#include "qmaterialshape.h"

class QMaterialButton : public QPushButton
{
    Q_OBJECT

public:
    enum ButtonType {
        Contained,
        Outlined,
        Text,
        Toggle
    };

public:
    QMaterialButton();

private:

    ButtonType m_type;
    QIcon m_icon;
    QMaterialOverlay m_current_overlay;
    QMaterialState m_state_machine;
    QMaterialTheme m_theme;
    QMaterialShape m_shape;
    QState m_current_state;
};

#endif // QMATERIALBUTTON_H
