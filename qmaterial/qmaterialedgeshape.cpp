#include "qmaterialedgeshape.h"

QMaterialEdgeShape::QMaterialEdgeShape(EdgeShapeType type) : m_type(type)
{}

void QMaterialEdgeShape::draw(QPainterPath &path, const QRect &rect, int size_dp)
{
    Q_UNUSED(size_dp)
    if (m_type == Diamond)
    {
        QVector<QPoint> points;
        ///
        ///       x1,y1
        ///  x4,y2 /\ x2, y2
        ///       \/
        ///       x1, y3
        ///
        ///
        int x1 = rect.center().x();
        int y1 = rect.top();
        QPoint p1(x1, y1);
        points.append(p1);

        int x2 = rect.right();
        int y2 = rect.center().y();
        QPoint p2(x2, y2);
        points.append(p2);

        int y3 = rect.bottom();
        QPoint p3(x1, y3);
        points.append(p3);

        int x4 = rect.left();
        QPoint p4(x4, y2);
        points.append(p4);

        points.append(p1);

        QPolygon pol(points);
        path.addPolygon(pol);

    }
    else if (m_type == Circle)
    {
        path.addEllipse(rect);
    }
    else // defaults to a square shape if (m_type == Square)
    {
        path.addRect(rect);
    }
}

QMaterialArrowShape::QMaterialArrowShape(ArrowShapeDir top,
                                         ArrowShapeDir right,
                                         ArrowShapeDir bottom,
                                         ArrowShapeDir left)
    : m_top(top), m_right(right), m_bottom(bottom), m_left(left)
{ }

void QMaterialArrowShape::draw(QPainterPath &path, const QRect &rect, int size_dp)
{
    QPoint tl = rect.topLeft();
    QPoint tr = rect.topRight();
    QPoint br = rect.bottomRight();
    QPoint bl = rect.bottomLeft();

    //bounding rect adaptation
    if(Out == m_top)
    {
        tl.ry() += size_dp;
        tr.ry() += size_dp;
    }
    if(Out == m_right)
    {
        tr.rx() -= size_dp;
        br.rx() -= size_dp;
    }
    if(Out == m_bottom)
    {
        br.ry() -= size_dp;
        bl.ry() -= size_dp;
    }
    if(Out == m_left)
    {
        bl.rx() += size_dp;
        tl.rx() += size_dp;
    }

    path.moveTo(tl);
    if (In == m_top)
    {
        QPoint pt(rect.center().x(), rect.top());
        path.lineTo(pt);
        path.lineTo(tr);
    }
    else if(Out == m_top)
    {
        QPoint pt(rect.center().x(), rect.top());
        path.lineTo(pt);
        path.lineTo(tr);
    }
    else
    {
        path.lineTo(tr);
    }

    if (In == m_right)
    {
        QPoint pt(rect.right(), rect.center().y());
        path.lineTo(pt);
        path.lineTo(br);
    }
    else if(Out == m_right)
    {
        QPoint pt(rect.right(), rect.center().y());
        path.lineTo(pt);
        path.lineTo(br);
    }
    else
    {
        path.lineTo(br);
    }

    if (In == m_bottom)
    {
        QPoint pt(rect.center().x() , rect.bottom());
        path.lineTo(pt);
        path.lineTo(bl);
    }
    else if(Out == m_bottom)
    {
        QPoint pt(rect.center().x() , rect.bottom());
        path.lineTo(pt);
        path.lineTo(bl);
    }
    else
    {
        path.lineTo(bl);
    }

    if (In == m_left)
    {
        QPoint pt(rect.left(), rect.center().y());
        path.lineTo(pt);
        path.lineTo(tl);
    }
    else if(Out == m_left)
    {
        QPoint pt(rect.left(), rect.center().y());
        path.lineTo(pt);
        path.lineTo(tl);
    }
    else
    {
        path.lineTo(tl);
    }

}
