#ifndef QMATERIALOVERLAY_H
#define QMATERIALOVERLAY_H

//!
//! \brief The QMaterialOverlay class
//! An overlay is a semi-transparent covering on an element, indicating state. Overlays provide a systematic approach to visualizing states using opacity.
//! The overlay can be applied to an entire element or in a circular shape. The overlay color matches the color of the text or iconography on the element it’s applied to.
//! If the text or iconography changes color during a state change, the overlay matches the end state's color.
//!
//! from:
//! https://material.io/design/interaction/states.html#anatomy
//!
class QMaterialOverlay
{
public:
    QMaterialOverlay();


private:

    //!
    //! \brief m_opacity - the applied opacity of the current overlay
    //!
    short m_opacity;

};

#endif // QMATERIALOVERLAY_H
