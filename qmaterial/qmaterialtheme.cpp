#include "qmaterialtheme.h"

QColor QMaterialTheme::color_secondary() const
{
    return m_color_secondary;
}

void QMaterialTheme::setColor_secondary(const QColor &color_secondary)
{
    m_color_secondary = color_secondary;
}

QColor QMaterialTheme::color_surface() const
{
    return m_color_surface;
}

void QMaterialTheme::setColor_surface(const QColor &color_surface)
{
    m_color_surface = color_surface;
}

QColor QMaterialTheme::color_background() const
{
    return m_color_background;
}

void QMaterialTheme::setColor_background(const QColor &color_background)
{
    m_color_background = color_background;
}

QColor QMaterialTheme::color_error() const
{
    return m_color_error;
}

void QMaterialTheme::setColor_error(const QColor &color_error)
{
    m_color_error = color_error;
}

short QMaterialTheme::shape_small_radius() const
{
    return m_shape_small_radius;
}

void QMaterialTheme::setShape_small_radius(short shape_small_radius)
{
    m_shape_small_radius = shape_small_radius;
}

QMaterialTheme::IconFamily QMaterialTheme::icon() const
{
    return m_icon;
}

void QMaterialTheme::setIcon(const IconFamily &icon)
{
    m_icon = icon;
}

short QMaterialTheme::shape_medium_radius() const
{
    return m_shape_medium_radius;
}

void QMaterialTheme::setShape_medium_radius(short shape_medium_radius)
{
    m_shape_medium_radius = shape_medium_radius;
}

short QMaterialTheme::shape_large_radius() const
{
    return m_shape_large_radius;
}

void QMaterialTheme::setShape_large_radius(short shape_large_radius)
{
    m_shape_large_radius = shape_large_radius;
}

QFont QMaterialTheme::typography() const
{
    return m_typography;
}

void QMaterialTheme::setTypography(const QFont &typography)
{
    m_typography = typography;
}

QColor QMaterialTheme::color_primary() const
{
    return m_color_primary;
}

void QMaterialTheme::setColor_primary(const QColor &color_primary)
{
    m_color_primary = color_primary;
}

QMaterialTheme QMaterialTheme::default_theme()
{
    QMaterialTheme theme;
    theme.m_color_primary = QColor("#fcb8ab");
    theme.m_color_secondary = QColor("#feeae6");
    theme.m_color_on_primary = QColor("#442b2d");
    theme.m_color_on_secondary = QColor("#442b2d");

    theme.m_shape_small_radius = 10;

    return theme;
}
