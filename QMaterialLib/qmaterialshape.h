#ifndef QMATERIASHAPE_H
#define QMATERIASHAPE_H


class QMaterialShape
{
public:
    enum ShapeCorner {
        Round, Cut
    };

public:
    QMaterialShape();

private:

    bool m_top_left_corner;
    bool m_top_right_corner;
    bool m_bottom_left_corner;
    bool m_bottom_right_corner;

    ShapeCorner m_shape_corner;


};

#endif // QMATERIASHAPE_H
