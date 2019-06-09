#include "qmaterialbutton.h"

#include <QMouseEvent>
#include <QPainter>

#include "qmaterialcornershape.h"
#include "qmaterialedgeshape.h"

QMaterialButton::QMaterialButton(const QString &text, QWidget *parent, QMaterialTheme theme)
    : QPushButton(text, parent), m_theme(theme),
      //m_shape(new QMaterialCornerShape(QMaterialCornerShape::Round, QMaterialCornerShape::Square, QMaterialCornerShape::Round, QMaterialCornerShape::Square))
      //m_shape(new QMaterialEdgeShape(QMaterialEdgeShape::Square))
      m_edge_shape(new QMaterialArrowShape(QMaterialArrowShape::None,
                                      QMaterialArrowShape::Out,
                                      QMaterialArrowShape::None,
                                      QMaterialArrowShape::None)),
      m_corner_shape(new QMaterialCornerShape(QMaterialCornerShape::Round))
{

}


/*!
 *  \reimp
 */
void QMaterialButton::mousePressEvent(QMouseEvent *event)
{
   // Q_D(QtMaterialFlatButton);
/*
    if (Material::NoRipple != d->rippleStyle)
    {
        QPoint pos;
        qreal radiusEndValue;

        if (Material::CenteredRipple == d->rippleStyle) {
            pos = rect().center();
        } else {
            pos = event->pos();
        }

        if (d->useFixedRippleRadius) {
            radiusEndValue = d->fixedRippleRadius;
        } else {
            radiusEndValue = static_cast<qreal>(width())/2;
        }

        QtMaterialRipple *ripple = new QtMaterialRipple(pos);

        ripple->setRadiusEndValue(radiusEndValue);
        ripple->setOpacityStartValue(0.35);
        ripple->setColor(foregroundColor());
        ripple->radiusAnimation()->setDuration(600);
        ripple->opacityAnimation()->setDuration(1300);

        d->rippleOverlay->addRipple(ripple);
    }
*/
    QPushButton::mousePressEvent(event);
}

/*!
 *  \reimp
 */
void QMaterialButton::mouseReleaseEvent(QMouseEvent *event)
{
   // Q_D(QtMaterialFlatButton);

    QPushButton::mouseReleaseEvent(event);

   // d->stateMachine->updateCheckedStatus();
}

void QMaterialButton::resizeEvent(QResizeEvent *event)
{
    QPushButton::resizeEvent(event);

    //updateClipPath();
}

/*!
 *  \reimp
 */
void QMaterialButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    //Q_D(QtMaterialFlatButton);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const short cr = m_theme.shape_small_radius();

    QPainterPath path;
    m_edge_shape->draw(path, this->rect(), cr);

    m_corner_shape->draw(path, this->rect(), cr);

    painter.setClipPath(path);
    painter.setClipping(true);

    paintBackground(&painter);
 //   paintHalo(&painter);

    painter.setOpacity(1);
    painter.setClipping(false);

    paintForeground(&painter);

    //QPushButton::paintEvent(event);
}

void QMaterialButton::paintBackground(QPainter *painter)
{
    //Q_D(QtMaterialFlatButton);

    //const qreal overlayOpacity = d->stateMachine->overlayOpacity();
    //const qreal checkedProgress = d->stateMachine->checkedOverlayProgress();

    if (true) //Qt::OpaqueMode == d->bgMode) {
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if (isEnabled()) {
            brush.setColor(m_theme.color_background());//backgroundColor());
        } else {
            brush.setColor(Qt::gray);//disabledBackgroundColor());
        }
        painter->setOpacity(1);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->drawRect(rect());
    }

    if (false)//Qt::TransparentMode == d->bgMode) {
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::blue);//(backgroundColor());
/*        if (isEnabled()) {
            brush.setColor(backgroundColor());
        } else {
            brush.setColor(disabledBackgroundColor());
        }
*/
        //painter->setOpacity(1);
        //painter->setBrush(brush);
        QPen pen(brush, 1, Qt::SolidLine);
        painter->setPen(pen);
        painter->drawRect(rect());
    }


    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter->setPen(Qt::NoPen);

    if (!isEnabled()) {
        return;
    }

   // if ((Material::NoOverlay != d->overlayStyle) && (overlayOpacity > 0)) {
        //if (Material::TintedOverlay == d->overlayStyle) {
        //    brush.setColor(overlayColor());
       // } else {
            brush.setColor(Qt::gray);
        //}
        painter->setOpacity(0.5);//overlayOpacity);
        painter->setBrush(brush);
        painter->drawRect(rect());
    //}
/*
    if (isCheckable() && checkedProgress > 0) {
        const qreal q = Qt::TransparentMode == d->bgMode ? 0.45 : 0.7;
        brush.setColor(foregroundColor());
        painter->setOpacity(q*checkedProgress);
        painter->setBrush(brush);
        QRect r(rect());
        r.setHeight(static_cast<qreal>(r.height())*checkedProgress);
        painter->drawRect(r);
    }
  */
}

void QMaterialButton::paintHalo(QPainter *painter)
{
//    Q_D(QtMaterialFlatButton);

  //  if (!d->haloVisible) {
    //    return;
    //}

    const qreal opacity = 0.5;//d->stateMachine->haloOpacity();
    const qreal s = 0.3;// d->stateMachine->haloScaleFactor()*d->stateMachine->haloSize();
    const qreal radius = static_cast<qreal>(width())*s;

    if (isEnabled() && opacity > 0) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(m_theme.color_primary());
        painter->setOpacity(opacity);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        const QPointF center = rect().center();
        painter->drawEllipse(center, radius, radius);
    }
}

#define COLOR_INTERPOLATE(CH) (1-progress)*source.CH() + progress*dest.CH()

void QMaterialButton::paintForeground(QPainter *painter)
{
//    Q_D(QtMaterialFlatButton);

    if (isEnabled()) {
        painter->setPen(Qt::black);//foregroundColor());
        //const qreal progress = d->stateMachine->checkedOverlayProgress();
        const qreal progress = 1;
        if (isCheckable()) //&& progress > 0)
        {
            QColor source = Qt::black;//foregroundColor();
            QColor dest = Qt::red;
            //QColor dest = Qt::TransparentMode == d->bgMode ? Qt::white
            //                                               : Qt::red;//backgroundColor();
            if (false)//(qFuzzyCompare(1, progress))
            {
                //painter->setPen(dest);
            } else
            {
                painter->setPen(QColor(COLOR_INTERPOLATE(red),
                                       COLOR_INTERPOLATE(green),
                                       COLOR_INTERPOLATE(blue),
                                       COLOR_INTERPOLATE(alpha)));
            }
        }
    } else {
        painter->setPen(Qt::gray);//disabledForegroundColor());
    }

    if (icon().isNull())  {
        if (Qt::AlignLeft == 1)//d->textAlignment)
        {
            painter->drawText(rect().adjusted(12, 0, 0, 0), Qt::AlignLeft | Qt::AlignVCenter, text());
        } else {
            painter->drawText(rect(), Qt::AlignCenter, text());
        }
        return;
    }

    QSize textSize(fontMetrics().size(Qt::TextSingleLine, text()));
    QSize base(size()-textSize);

    const int iw = iconSize().width() + 1;//IconPadding;
    QPoint pos(Qt::AlignLeft == 1/* d->textAlignment*/ ? 12 : (base.width()-iw)/2, 0);

    QRect textGeometry(pos + QPoint(0, base.height()/2), textSize);
    QRect iconGeometry(pos + QPoint(0, (height()-iconSize().height())/2), iconSize());

    //if (Material::LeftIcon == d->iconPlacement) {
     //   textGeometry.translate(iw, 0);
    //} else {
        iconGeometry.translate(textSize.width() + 1 /* IconPadding */, 0);
   // }

    painter->drawText(textGeometry, Qt::AlignCenter, text());

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), painter->pen().color());
    painter->drawPixmap(iconGeometry, pixmap);
}
