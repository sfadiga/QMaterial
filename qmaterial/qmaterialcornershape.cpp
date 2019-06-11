#include "qmaterialcornershape.h"

#include <QtMath>

QMaterialCornerShape::QMaterialCornerShape(ShapeCornerType type)
    : m_corners(QVector<ShapeCornerType>(1, type))
{}

QMaterialCornerShape::QMaterialCornerShape(const QVector<QMaterialCornerShape::ShapeCornerType> &types)
    : m_corners(types)
{}


void QMaterialCornerShape::draw(QPainterPath &path, const QRect &rect, int size_dp)
{
    ///
    ///
    /// p1,p2/-------\p3,p4
    ///      |       |
    /// p8,p7\-------/p5,p6

    QPointF p0;
    QPainterPath m_path;
    // TODO testing other solutions
    for(int i = 0; i < path.elementCount(); i++)
    {
        QPointF p1 = path.elementAt(i); //get the value of the point at index i
        QPointF p2 = path.elementAt((i+1) % path.elementCount());

        // Variable fRat holds the ratio between the radius and the i-th line segment length.
        // There is also a check that prevents fRat from having a value over 0.5.
        // If fRat had a value over 0.5, then the two consecutive rounded corners would overlap,
        // which would cause a poor visual result.
        qreal ratio = static_cast<qreal>(size_dp) / sqrt(QPointF::dotProduct(p1, p2)); // GetDistance(p1, p2);
        if (ratio > 0.5)
            ratio = 0.5;

        QPointF pt1((1.0 - ratio) * p1.x() + ratio * p2.x(), (1.0 - ratio) * p1.y() + ratio * p2.y());

        if (i == 0)
        {
            m_path.moveTo(pt1);
            p0 = pt1;
        }
        else
        {
            m_path.quadTo(p1, pt1);
        }

        QPointF pt2(ratio * p1.x() + (1.0 - ratio) * p2.x(), ratio*p1.y() + (1.0 - ratio) * p2.y());

        m_path.lineTo(pt2);
    }

    // close the last corner
    m_path.quadTo(path.elementAt(0), p0);

    path = m_path;


/*

    QPoint tl = rect.topLeft();
    QPoint p1(tl);
    p1.ry() += size_dp/2;
    QPoint p2(tl);
    p2.rx() += size_dp/2;

    if (QMaterialCornerShape::Cut == m_c1)
    {
        path.lineTo(p1);
        path.lineTo(p2);
    }
    else if (QMaterialCornerShape::Round == m_c1)
    {
        path.moveTo(p1);
        path.quadTo(tl, p2);
    }
    else // default shape
    {
        path.lineTo(p1);
        path.lineTo(tl);
        path.lineTo(p2);
    }

    QPoint tr = rect.topRight();
    QPoint p3(tr);
    p3.rx() -= size_dp/2;
    QPoint p4(tr);
    p4.ry() += size_dp/2;

    if (QMaterialCornerShape::Cut == m_c2)
    {
        path.lineTo(p3);
        path.lineTo(p4);

    }
    else if (QMaterialCornerShape::Round == m_c2)
    {
        path.lineTo(p3);
        path.quadTo(tr, p4);
    }
    else // default shape
    {
        path.lineTo(p3);
        path.lineTo(tr);
        path.lineTo(p4);
    }

    QPoint br = rect.bottomRight();
    QPoint p5(br);
    p5.ry() -= size_dp/2;
    QPoint p6(br);
    p6.rx() -= size_dp/2;

    if (QMaterialCornerShape::Cut == m_c3)
    {
        path.lineTo(p5);
        path.lineTo(p6);

    }
    else if (QMaterialCornerShape::Round == m_c3)
    {
        path.lineTo(p5);
        path.quadTo(br,p6);
    }
    else // default shape
    {
        path.lineTo(p5);
        path.lineTo(br);
        path.lineTo(p6);
    }

    QPoint bl = rect.bottomLeft();
    QPoint p7(bl);
    p7.rx() += size_dp/2;
    QPoint p8(bl);
    p8.ry() -= size_dp/2;

    if (QMaterialCornerShape::Cut == m_c4)
    {
        path.lineTo(p7);
        path.lineTo(p8);

    }
    else if (QMaterialCornerShape::Round == m_c4)
    {
        path.lineTo(p7);
        path.quadTo(bl, p8);
    }
    else // default shape
    {
        path.lineTo(p7);
        path.lineTo(bl);
        path.lineTo(p8);
    }

    path.lineTo(p1);
*/
}
