#ifndef QMATERIALEDGESHAPE_H
#define QMATERIALEDGESHAPE_H

#include "qmaterialshape.h"

//!
//! \brief The QMaterialEdgeShape class
//!
class QMaterialEdgeShape : public QMaterialShape
{
public:
    enum EdgeShapeType {
      Diamond, Circle, Square
    };

public:
    QMaterialEdgeShape(EdgeShapeType type);
    ~QMaterialEdgeShape() override = default;

    // QMaterialShape interface
public:
    void draw(QPainterPath &path, const QRect &rect, int size_dp) override;


private:
    EdgeShapeType m_type;
};


//!
//! \brief The QMaterialArrowShape class
//!
class QMaterialArrowShape : public QMaterialShape
{
public:
    enum ArrowShapeDir {
        In, Out, None
    };

public:
    QMaterialArrowShape(ArrowShapeDir m_top = None, ArrowShapeDir m_right = None, ArrowShapeDir m_bottom = None, ArrowShapeDir m_left = None);
    ~QMaterialArrowShape() override = default;

    // QMaterialShape interface
public:
    void draw(QPainterPath &path, const QRect &rect, int size_dp) override;

private:
    ArrowShapeDir m_top;
    ArrowShapeDir m_right;
    ArrowShapeDir m_bottom;
    ArrowShapeDir m_left;
};



#endif // QMATERIALEDGESHAPE_H

