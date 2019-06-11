#ifndef QMATERIALSHAPE_H
#define QMATERIALSHAPE_H

#include <QRect>
#include <QPainterPath>

//!
//! \brief The QMaterialShape class
//!
class QMaterialShape
{
public:

    virtual void draw(QPainterPath &path, const QRect &rect, int size_dp) = 0;
    virtual ~QMaterialShape() = default;

};


#endif // QMATERIALSHAPE_H
