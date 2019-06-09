#ifndef QMATERIALCORNERSHAPE_H
#define QMATERIALCORNERSHAPE_H

#include "qmaterialshape.h"

//!
//! \brief The QMaterialCornerShape class
//!
//!  c1------c2
//!  \        \
//!  c4------c3
//!
class QMaterialCornerShape : public QMaterialShape
{
public:
    enum ShapeCornerType {
        Round, Cut, Square
    };

public:
    QMaterialCornerShape(ShapeCornerType type);
    QMaterialCornerShape(ShapeCornerType c1,
                         ShapeCornerType c2,
                         ShapeCornerType c3,
                         ShapeCornerType c4);

    ~QMaterialCornerShape() override = default;

private:
    ShapeCornerType m_c1;
    ShapeCornerType m_c2;
    ShapeCornerType m_c3;
    ShapeCornerType m_c4;

    // QMaterialShape interface
public:
    void draw(QPainterPath &path, const QRect &rect, int size_dp) override;
};

#endif // QMATERIALCORNERSHAPE_H
