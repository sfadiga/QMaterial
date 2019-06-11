#ifndef QMATERIALCORNERSHAPE_H
#define QMATERIALCORNERSHAPE_H

#include "qmaterialshape.h"

#include <QMap>
#include <QPainterPath>

//!
//! \brief The QMaterialCornerShape class
//!
//!  ex 1:
//!  c1------c2
//!  \        \
//!  c4------c3
//!
//!  ex 2:
//!  c1------c2
//!  \          > c3
//!  c5------c4
//!
//! Points added to the corner shape are in the order of the images above TODO enhance description
//!
class QMaterialCornerShape : public QMaterialShape
{
public:
    enum ShapeCornerType {
        Round, Cut, Square
    };

public:
    //!
    //! \brief QMaterialCornerShape - create a corners that uses shapes of the same type
    //! \param type - the type of the corner, based on enum ShapeCornerType
    //!
    //!
    QMaterialCornerShape(ShapeCornerType type);

    QMaterialCornerShape(const QVector<ShapeCornerType> &types);

    ~QMaterialCornerShape() override = default;

    // QMaterialShape interface
public:
    void draw(QPainterPath &path, const QRect &rect, int size_dp) override;

protected:
    QPointF GetLineStart(int i) const;
    QPointF GetLineEnd(int i) const;

private:
    QVector<ShapeCornerType> m_corners;

    ShapeCornerType cornerTypeIndex(int i);
};

#endif // QMATERIALCORNERSHAPE_H
