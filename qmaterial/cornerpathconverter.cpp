#include "cornerpathconverter.h"


QPainterPath& RoundCornerPathConverter::convertTo(const QPainterPath& path, int size_dp)
{
    /*
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
    */

    // TODO testing other solutions
    for(int i = 0; i < path.elementCount(); i++)
    {
        QPointF pt = path.elementAt(i); //get the value of the point at index i


        //path.setElementPositionAt(i, 3, 1416); //change the value of the point at index i
    }
/*

    QPainterPath m_path;

    if (count() < 3) {
     qWarning() << "Polygon should have at least 3 points!";
     return m_path;
    }

    QPointF pt1;
    QPointF pt2;
    for (int i = 0; i < count(); i++)
    {
         pt1 = GetLineStart(i);

         if (i == 0)
             m_path.moveTo(pt1);
         else
             m_path.quadTo(at(i), pt1);

         pt2 = GetLineEnd(i);
         m_path.lineTo(pt2);
    }

    // close the last corner
    pt1 = GetLineStart(0);
    m_path.quadTo(at(0), pt1);

    return m_path;
    */
}
