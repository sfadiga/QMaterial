#include "qmaterialcornershape.h"


QMaterialCornerShape::QMaterialCornerShape(ShapeCornerType type)
    : QMaterialCornerShape(type, type, type, type)
{}

QMaterialCornerShape::QMaterialCornerShape(ShapeCornerType c1,
                                           ShapeCornerType c2,
                                           ShapeCornerType c3,
                                           ShapeCornerType c4) :
    m_c1(c1), m_c2(c2), m_c3(c3), m_c4(c4)
{}

void QMaterialCornerShape::draw(QPainterPath &path, const QRect &rect, int size_dp)
{
    ///
    ///
    /// p1,p2/-------\p3,p4
    ///      |       |
    /// p8,p7\-------/p5,p6


    // TODO testing other solutions
    QPolygonF polygon = path.toFillPolygon();
    QList<QLineF> edgeList;
    for (int i=0 ; i < polygon.count() ; i++)
    {
         QLineF edge;
         if(i != (polygon.count() - 1))
         {
             edge.setPoints(polygon.at(i),polygon.at(i + 1));
         }
         else
         {
             edge.setPoints(polygon.at(i),polygon.at(0));
         }
         edgeList << edge;
     }

    // TODO testing other solutions
    for(int i = 0; i < path.elementCount(); i++)
    {
        QPointF pt = path.elementAt(i); //get the value of the point at index i
        //path.setElementPositionAt(i, 3, 1416); //change the value of the point at index i
    }

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

}
