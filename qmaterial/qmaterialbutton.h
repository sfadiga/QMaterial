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
    QMaterialButton(const QString &text, QWidget *parent = nullptr, QMaterialTheme theme = QMaterialTheme::default_theme());

protected:
   // void checkStateSet() override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    virtual void paintBackground(QPainter *painter);
    virtual void paintHalo(QPainter *painter);
    virtual void paintForeground(QPainter *painter);
    //virtual void updateClipPath();


private:
    Q_DISABLE_COPY(QMaterialButton)

private:

    ButtonType m_type;

    QMaterialTheme m_theme;
    QMaterialShape* m_edge_shape;  // TODO smart pointer here...
    QMaterialShape* m_corner_shape; // TODO smart pointer here...

    //QMaterialStyle m_style;

    QMaterialOverlay m_current_overlay;
    QMaterialState m_state_machine;
    QState m_current_state;

    Qt::BGMode m_background_mode;
    Qt::Alignment m_text_alignment;



};

#endif // QMATERIALBUTTON_H
