// ----------------------------------------------------------------------------
//
//
// OpenSteer -- Steering Behaviors for Autonomous Characters
//
// Copyright (c) 2002-2003, Sony Computer Entertainment America
// Original author: Craig Reynolds <craig_reynolds@playstation.sony.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
//
// ----------------------------------------------------------------------------
//
//
// AbstractVehicle: pure virtual base class for generic steerable vehicles
//
// 01-30-03 cwr: created 
//
//
// ----------------------------------------------------------------------------

#ifndef _OPENSTEER_ABSTRACTVEHICLE_H_
#define _OPENSTEER_ABSTRACTVEHICLE_H_


#include "LocalSpace.h"


// STL vector containers
#include <vector>


// ----------------------------------------------------------------------------


class AbstractVehicle : public AbstractLocalSpace 
{
public:

    // mass (defaults to unity so acceleration=force)
    virtual float mass (void) const = 0;
    virtual float setMass (float) = 0;

    // size of bounding sphere, for obstacle avoidance, etc.
    virtual float radius (void) const = 0;
    virtual float setRadius (float) = 0;

    // velocity of vehicle
    virtual Vec3 velocity (void) const = 0;

    // speed of vehicle  (may be faster than taking magnitude of velocity)
    virtual float speed (void) const = 0;
    virtual float setSpeed (float) = 0;

    // groups of (pointers to) abstract vehicles, and iterators over them
    typedef vector<AbstractVehicle*> group;
    typedef group::const_iterator iterator;    

    // predict position of this vehicle at some time in the future
    // (assumes velocity remains constant)
    virtual Vec3 predictFuturePosition (const float predictionTime) const = 0;

    // ----------------------------------------------------------------------
    // XXX this vehicle-model-specific functionality functionality seems out
    // XXX of place on the abstract base class, but for now it is expedient

    // the maximum steering force this vehicle can apply
    virtual float maxForce (void) const = 0;
    virtual float setMaxForce (float) = 0;

    // the maximum speed this vehicle is allowed to move
    virtual float maxSpeed (void) const = 0;
    virtual float setMaxSpeed (float) = 0;
};


// more convenient short names for AbstractVehicle group and iterator
typedef AbstractVehicle::group AVGroup;
typedef AbstractVehicle::iterator AVIterator;


// ----------------------------------------------------------------------------
#endif // _OPENSTEER_ABSTRACTVEHICLE_H_
