#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

#include "Sculptor.h"

/**
 * The GeometricFigure is an abstract superclass that implements
 * polimorfism for the Sculptor class' drawing methods through the
 * draw method.
 *
 */
class GeometricFigure
{
public:
    GeometricFigure();
    virtual ~GeometricFigure();
    /**
     * The draw method is used by the child classes to implement
     * the drawing methods from the Sculptor class, which are
     * executed upon the given Sculptor object.
     *
     * @param t A Sculptor object passed by reference to be drawn on.
     *
     */
    virtual void draw(Sculptor &t) = 0;
};

#endif