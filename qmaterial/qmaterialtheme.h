#ifndef QMATERIALTHEME_H
#define QMATERIALTHEME_H

#include <QColor>
#include <QFont>

//!
//! \brief The QMaterialTheme class
//!
class QMaterialTheme
{
public:
    enum IconFamily
    {
        Filled, Outlined
    };

public:
    QMaterialTheme() = default;
    ~QMaterialTheme() = default;

    QColor color_primary() const;
    void setColor_primary(const QColor &color_primary);

    QColor color_secondary() const;
    void setColor_secondary(const QColor &color_secondary);

    QColor color_surface() const;
    void setColor_surface(const QColor &color_surface);

    QColor color_background() const;
    void setColor_background(const QColor &color_background);

    QColor color_error() const;
    void setColor_error(const QColor &color_error);

    short shape_small_radius() const;
    void setShape_small_radius(short shape_small_radius);

    short shape_medium_radius() const;
    void setShape_medium_radius(short shape_medium_radius);

    short shape_large_radius() const;
    void setShape_large_radius(short shape_large_radius);

    QFont typography() const;
    void setTypography(const QFont &typography);

    IconFamily icon() const;
    void setIcon(const IconFamily &icon);

    //!
    //! \brief default_theme
    //! \return
    //!
    static QMaterialTheme default_theme();

private:

    /* Color */
    // To change your theme's color scheme, replace the existing HEX color values with custom HEX color values. Use our color palette generator to help come up with pairings and check your color contrast. https://material.io/design/color/the-color-system.html#tools-for-picking-colors
    // Primary colors ($mdc-theme-primary) map to components such as app bars and buttons, while secondary colors ($mdc-theme-secondary) are used as accents on components such as FABs and selection controls.
    QColor m_color_primary;
    QColor m_color_secondary;

    // Theme background ($mdc-theme-background) appears behind scrollable content. Surface color ($mdc-theme-surface) is mapped to the surface of components such as cards, sheets, and menus. Error color ($mdc-theme-error) is used to indicate an error state for components such as text fields provided with inaccurate input.
    QColor m_color_surface;
    QColor m_color_background;
    QColor m_color_error;

    // “On-” colors define how text, icons, and strokes are colored in relation to the surface on which they appear. If you are updating these manually, be sure to consider accessible color contrast for the value pairs.
    QColor m_color_on_primary;
    QColor m_color_on_secondary;
    QColor m_color_on_error;
    QColor m_color_on_surface;

    /* Shape */
    // The shapes of small, medium, and large components can be themed by overriding the default values. We recommend using our shape customization tool to help you pick your radius values. https://material.io/design/shape/about-shape.html#shape-customization-tool
    short m_shape_small_radius;
    short m_shape_medium_radius;
    short m_shape_large_radius;

    /*  Typography */
    // To change your theme's typography, we recommend importing a font from Google Fonts and setting the global font-family https://fonts.google.com
    QFont m_typography;

    /* Icon family */
    IconFamily m_icon;

};

#endif // QMATERIALTHEME_H
