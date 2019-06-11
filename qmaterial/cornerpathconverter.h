#ifndef CORNERPATHCONVERTER_H
#define CORNERPATHCONVERTER_H

#include <QPainterPath>

//!
//! \brief The CornerPathConverter class
//!
class CornerPathConverter
{
public:
    virtual QPainterPath& convertTo(const QPainterPath& path, int size_dp) = 0;
    virtual ~CornerPathConverter() = default;
};

class RoundCornerPathConverter : public CornerPathConverter
{
    Q_DISABLE_COPY(RoundCornerPathConverter)
public:
    RoundCornerPathConverter() = default;
    ~RoundCornerPathConverter() = default;

    // CornerPathConverter interface
public:
    QPainterPath &convertTo(const QPainterPath& path, int size_dp);

};

#endif // CORNERPATHCONVERTER_H
