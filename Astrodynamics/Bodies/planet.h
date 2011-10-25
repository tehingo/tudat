/*! \file planet.h
 *    Header file that contains the planet class in Tudat.
 *
 *    Path              : /Astrodynamics/Bodies/
 *    Version           : 1
 *    Check status      : Checked
 *
 *    Author            : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Checker           : J. Melman
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : J.C.P.Melman@tudelft.nl
 *
 *    Date created      : 23 July, 2011
 *    Last modified     : 23 July, 2011
 *
 *    References
 *
 *    Notes
 *
 *    Copyright (c) 2010-2011 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      110623    K. Kumar          First creation of code.
 */

#ifndef PLANET_H
#define PLANET_H

// Include statements.
#include "Astrodynamics/Bodies/celestialBody.h"
#include "Astrodynamics/EnvironmentModels/centralGravityField.h"
#include "Astrodynamics/States/approximatePlanetPositions.h"

//! Planet class.
/*!
 * Class that contains planet properties.
 */
class Planet : public CelestialBody
{
public:

    //! Predefined planets
    /*!
     * Predefined planets.
     */
    enum PredefinedPlanets
    { sun, mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune };

    //! Set predefined planet settings.
    /*!
     * Sets predefined planet settings.
     * \param predefinedPlanet Predefined planet.
     */
    void setPredefinedPlanetSettings( PredefinedPlanets predefinedPlanet );

protected:

private:

    //! Predefined central gravity field.
    /*!
     * Predefined central gravity field.
     */
    CentralGravityField predefinedCentralGravityField_;

    //! Approximate planet positions ephemeris.
    /*!
     * JPL apprximate planet positions ephemeris.
     */
    ApproximatePlanetPositions approximatePlanetPositions_;
};

#endif // PLANET_H

// End of file.