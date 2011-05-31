/*! \file unitTestBasicMathematicsFunctions.cpp
 *    Source file that defines the unitTestBasicMathematicsFunctions unit test,
 *    containing all basic mathematics functions contained in Tudat.
 *
 *    Path              : /Mathematics/
 *    Version           : 3
 *    Check status      : Checked
 *
 *    Author            : B. Romgens
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : bart.romgens@gmail.com
 *
 *    Checker           : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Date created      : 7 February, 2011
 *    Last modified     : 11 April, 2011
 *
 *    References
 *
 *    Notes
 *
 *    Copyright (c) 2010 Delft University of Technology.
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
 *      110207    B. Romgens        File created.
 *      110215    K. Kumar          Minor modifications to layout, comments
 *                                  and variable-naming.
 *      110411    K. Kumar          Added unit test for
 *                                  convertCartesianToSpherical() function.
 */

// Include statements.
#include "unitTestBasicMathematicsFunctions.h"

// Using declarations.
using std::cerr;
using std::endl;
using mathematics::MACHINE_PRECISION_DOUBLES;
using mathematics::computeAbsoluteValue;
using mathematics::raiseToIntegerPower;
using mathematics::computeModulo;
using mathematics::convertCylindricalToCartesian;
using mathematics::convertSphericalToCartesian;
using mathematics::computeLinearInterpolation;
using mathematics::convertCartesianToSpherical;

//! Namespace for all unit tests.
namespace unit_tests
{

//! Test of implementation of basic mathematics functions.
bool testBasicMathematicsFunctions( )
{

    // Test resultUsingModuloFunction initialised to false.
    bool isBasicMathematicsFunctionsErroneous = false;

    // Test absolute value for doubles.
    // Test 1: Test absolute value function for double value 2.5.
    // Test 2: Test absolute value function for double value -2.5.

    double absoluteValueDouble = computeAbsoluteValue( 2.5 );

    if ( abs( absoluteValueDouble - 2.5 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The double absolute value function does not "
             << "function correctly for doubles. The computed value: "
             << absoluteValueDouble << " does not match the expected value: "
             << 2.5 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    absoluteValueDouble = computeAbsoluteValue( -2.5 );

    if ( abs( absoluteValueDouble - 2.5 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The double absolute value function does not "
             << "function correctly for doubles. The computed value: "
             << absoluteValueDouble << " does not match the expected value: "
             << 2.5 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test absolute value for integers.
    // Test 3: Test absolute value function for integer value 2.
    // Test 4: Test absolute value function for integer value -2.

    int absoluteValueInt = computeAbsoluteValue( 2 );

    if ( absoluteValueInt - 2 > 0 )
    {
        cerr << "The double absolute value function does not "
             << "function correctly for integers. The computed value: "
             << absoluteValueInt << " does not match the expected value: "
             << 2 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    absoluteValueInt = computeAbsoluteValue( -2 );

    if ( absoluteValueInt - 2 > 0 )
    {
        cerr << "The double absolute value function does not "
             << "function correctly for integers. The computed value: "
             << absoluteValueInt << " does not match the expected value: "
             << 2 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test integer powerValue.
    // Test 5: Test 0.0^0.
    // Test 6: Test 1.0^0.
    // Test 7: Test 0.0^1.
    // Test 8: Test 2.0^-2.
    // Test 9: Test 2.0^6.

    double powerValue = raiseToIntegerPower( 0.0, 0 );

    if ( powerValue != powerValue)
    {
        cerr << "The raiseToIntegerPower function does not "
             << "function correctly, as the computed value: " << powerValue
             << " does not match the expected value: " << 0.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    powerValue = raiseToIntegerPower( 1.0, 0 );

    if ( abs( powerValue - 1.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The raiseToIntegerPower function does not "
             << "function correctly, as the computed value: " << powerValue
             << " does not match the expected value: " << 1.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    powerValue = raiseToIntegerPower( 0.0, 1 );

    if ( abs( powerValue - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The raiseToIntegerPower function does not "
             << "function correctly, as the computed value: " << powerValue
             << " does not match the expected value: " << 0.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    powerValue = raiseToIntegerPower( 2.0, -2 );

    if ( abs( powerValue - 0.25 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The raiseToIntegerPower function does not "
             << "function correctly, as the computed value: " << powerValue
             << " does not match the expected value: " << 0.25 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    powerValue = raiseToIntegerPower( 2.0, 6 );

    if ( abs( powerValue - 64.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The raiseToIntegerPower function does not "
             << "function correctly, as the computed value: " << powerValue
             << " does not match the expected value: " << 64.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test modulo function.
    // Test 10: Test 0.0 mod 0.0.
    // Test 11: Test 2.0 mod 0.0.
    // Test 12: Test 2.0 mod 2.0.
    // Test 13: Test 3.0 mod 2.5.
    // Test 14: Test 3.0 mod -2.5.
    double resultUsingModuloFunction = computeModulo( 0.0, 0.0 );

    if ( abs( resultUsingModuloFunction - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeModulo function does not "
             << "function correctly, as the computed value: "
             << resultUsingModuloFunction
             << " does not match the expected value: " << 0.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    resultUsingModuloFunction = computeModulo( 2.0, 0.0 );

    if ( abs( resultUsingModuloFunction - 2.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeModulo function does not "
             << "function correctly, as the computed value: "
             << resultUsingModuloFunction
             << " does not match the expected value: " << 2.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    resultUsingModuloFunction = computeModulo( 2.0, 2.0 );

    if ( abs( resultUsingModuloFunction - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeModulo function does not "
             << "function correctly, as the computed value: "
             << resultUsingModuloFunction
             << " does not match the expected value: " << 0.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    resultUsingModuloFunction = computeModulo( 3.0, 2.5 );

    if ( abs( resultUsingModuloFunction -0.5 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeModulo function does not "
             << "function correctly, as the computed value: "
             << resultUsingModuloFunction
             << " does not match the expected value: " << -0.5 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    resultUsingModuloFunction = computeModulo( 3.0, -2.5 );

    if ( abs( resultUsingModuloFunction + 2.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeModulo function does not "
             << "function correctly, as the computed value: "
             << resultUsingModuloFunction
             << " does not match the expected value: " << -2.0 << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test conversion from cylindrical to Cartesian coordinates,
    // z value left unaffected.
    // Test 15: Test conversion of ( 2.0, 0.0 ).
    // Test 16: Test conversion of ( 2.0, pi ).
    // Test 17: Test conversion of ( 2.0, -2pi ).
    // Test 18: Test conversion of ( 2.0, 225 deg ).
    // Test 19: Test conversion of ( 2.0, -225 deg ).
    VectorXd cartesianCoordinates( 2 );

    convertCylindricalToCartesian( 2.0, 0.0, cartesianCoordinates );

    if ( abs( cartesianCoordinates( 0 ) - 2.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates( 1 ) - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, no z, function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " ) do not match the expected coordinates: ( 2.0, 0.0 )"
             << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertCylindricalToCartesian( 2.0, M_PI, cartesianCoordinates );

    if ( abs( cartesianCoordinates( 0 ) + 2.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates( 1 ) - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, no z, function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " ) do not match the expected coordinates: ( -2.0, 0.0 )"
             << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertCylindricalToCartesian( 2.0, -2.0*M_PI, cartesianCoordinates );

    if ( abs( cartesianCoordinates( 0 ) - 2.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates( 1 ) - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, no z, function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " ) do not match the expected coordinates: ( 2.0, 0.0 )"
             << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertCylindricalToCartesian( 2.0, 225.0/180.0*M_PI, cartesianCoordinates );

    if ( abs( cartesianCoordinates( 0 ) + sqrt( 2.0 ) ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates( 1 ) + sqrt( 2.0 )) >  MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, no z, function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " ) do not match the expected coordinates: ( "
             << -sqrt( 2.0 ) << ", " << -sqrt( 2.0 ) << " )" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertCylindricalToCartesian( 2.0, -225.0/180.0*M_PI, cartesianCoordinates );

    if ( abs( cartesianCoordinates( 0 ) + sqrt( 2.0 ) ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates( 1 ) - sqrt( 2.0 )) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, no z, function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " ) do not match the expected coordinates: ( "
             << -sqrt( 2.0 ) << ", " << sqrt( 2.0 ) << " )" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test conversion from spherical to Cartesian coordinates.
    // Test 20: Test conversion of: ( 0.0, 0.0, 0.0 ).
    // Test 21: Test conversion of: ( 2.0, 225, 225 ).
    // Test 22: Test conversion of: ( 2.0, -225, -225 ).
    // Test 23: Test conversion of: ( 2.0, 180, 180 ).
    VectorXd cartesianCoordinates3( 3 );

    convertSphericalToCartesian( 0.0, 0.0, 0.0, cartesianCoordinates3 );

    if ( abs( cartesianCoordinates3( 0 ) + 0.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 1 ) - 0.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 2 ) - 0.0 ) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian, function does not "
             << "function correctly. (test1)" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertSphericalToCartesian( 2.0, 225.0 / 180.0 * M_PI,
                                 225.0 / 180.0 * M_PI, cartesianCoordinates3 );

    if ( abs( cartesianCoordinates3( 0 ) - 1.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 1 ) - 1.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 2 ) + sqrt( 2.0 ) ) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " , " << cartesianCoordinates( 2 ) << " ) do not match the "
             << "expected coordinates: ( " << 1.0 << ", " << 1.0 << ", "
             << -sqrt( 2.0 ) << " )" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertSphericalToCartesian( 2.0, -225.0 / 180.0 * M_PI,
                                 -225.0 / 180.0 * M_PI,
                                 cartesianCoordinates3 );

    if ( abs( cartesianCoordinates3( 0 ) + 1.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 1 ) - 1.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 2 ) + sqrt( 2.0 ) ) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " , " << cartesianCoordinates( 2 ) << " ) do not match the "
             << "expected coordinates: ( " << -1.0 << ", " << 1.0 << ", "
             << -sqrt( 2.0 ) << " )" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    convertSphericalToCartesian( 2.0, 180.0 / 180.0 * M_PI,
                                 180.0 / 180.0 * M_PI, cartesianCoordinates3 );

    if ( abs( cartesianCoordinates3( 0 ) - 0.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 1 ) - 0.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( cartesianCoordinates3( 2 ) + 2.0 ) >  MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCylindricalToCartesian function does not "
             << "function correctly, as the computed coordinates: ( "
             << cartesianCoordinates( 0 ) << ", " << cartesianCoordinates( 1 )
             << " , " << cartesianCoordinates( 2 ) << " ) do not match the "
             << "expected coordinates: ( " << 0.0 << ", " << 0.0 << ", "
             << -2.0 << " )" << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test conversion from Cartesian to spherical coordinates.
    // Test 24: Test conversion of: ( 0.0, 0.0, 0.0 ).
    // Test 25: Test conversion of: ( 2.0, 3.5, -4.1 ).
    // Test 26: Test conversion of: ( 5.2, -6.3, 0.0 ).
    // Test 27: Test conversion of: ( 0.0, 12.2, -0.9 ).

    // Cartesian coordinates.
    VectorXd cartesianCoordinatesTest24_( 3 );
    cartesianCoordinatesTest24_.Zero( 3 );

    VectorXd cartesianCoordinatesTest25_( 3 );
    cartesianCoordinatesTest25_( 0 ) = 2.0;
    cartesianCoordinatesTest25_( 1 ) = 3.5;
    cartesianCoordinatesTest25_( 2 ) = -4.1;

    VectorXd cartesianCoordinatesTest26_( 3 );
    cartesianCoordinatesTest26_( 0 ) = 5.2;
    cartesianCoordinatesTest26_( 1 ) = -6.3;
    cartesianCoordinatesTest26_( 2 ) = 0.0;

    VectorXd cartesianCoordinatesTest27_( 3 );
    cartesianCoordinatesTest27_( 0 ) = 0.0;
    cartesianCoordinatesTest27_( 1 ) = 12.2;
    cartesianCoordinatesTest27_( 2 ) = -0.9;

    // Expected vectors in spherical coordinates.
    VectorXd expectedSphericalCoordinatesTest24_( 3 );
    expectedSphericalCoordinatesTest24_.Zero( 3 );

    VectorXd expectedSphericalCoordinatesTest25_( 3 );
    expectedSphericalCoordinatesTest25_( 0 )
            = sqrt( pow( cartesianCoordinatesTest25_( 0 ), 2.0 )
                    + pow( cartesianCoordinatesTest25_( 1 ), 2.0 )
                    + pow( cartesianCoordinatesTest25_( 2 ), 2.0 ) );
    expectedSphericalCoordinatesTest25_( 1 )
            = atan2( cartesianCoordinatesTest25_( 1 ),
                     cartesianCoordinatesTest25_( 0 ) );
    expectedSphericalCoordinatesTest25_( 2 )
            = acos( cartesianCoordinatesTest25_( 2 ) /
                     expectedSphericalCoordinatesTest25_( 0 ) );

    VectorXd expectedSphericalCoordinatesTest26_( 3 );
    expectedSphericalCoordinatesTest26_( 0 )
            = sqrt( pow( cartesianCoordinatesTest26_( 0 ), 2.0 )
                    + pow( cartesianCoordinatesTest26_( 1 ), 2.0 )
                    + pow( cartesianCoordinatesTest26_( 2 ), 2.0 ) );
    expectedSphericalCoordinatesTest26_( 1 )
            = atan2( cartesianCoordinatesTest26_( 1 ),
                     cartesianCoordinatesTest26_( 0 ) );
    expectedSphericalCoordinatesTest26_( 2 )
            = acos( cartesianCoordinatesTest26_( 2 ) /
                     expectedSphericalCoordinatesTest26_( 0 ) );

    VectorXd expectedSphericalCoordinatesTest27_( 3 );
    expectedSphericalCoordinatesTest27_( 0 )
            = sqrt( pow( cartesianCoordinatesTest27_( 0 ), 2.0 )
                    + pow( cartesianCoordinatesTest27_( 1 ), 2.0 )
                    + pow( cartesianCoordinatesTest27_( 2 ), 2.0 ) );
    expectedSphericalCoordinatesTest27_( 1 )
            = atan2( cartesianCoordinatesTest27_( 1 ),
                     cartesianCoordinatesTest27_( 0 ) );
    expectedSphericalCoordinatesTest27_( 2 )
            = acos( cartesianCoordinatesTest27_( 2 ) /
                     expectedSphericalCoordinatesTest27_( 0 ) );

    // Result vector in spherical coordinates.
    VectorXd sphericalCoordinates_( 3 );

    // Test 24: Test conversion of: ( 0.0, 0.0, 0.0 ).
    VectorXd differences_( 3 );
    differences_ = sphericalCoordinates_ - expectedSphericalCoordinatesTest24_;
    convertCartesianToSpherical( cartesianCoordinatesTest24_, sphericalCoordinates_ );

    if ( differences_.norm( ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCartesianToSpherical, function does not "
             << "function correctly. ( Test 24 )." << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test 25: Test conversion of: ( 2.0, 3.5, -4.1 ).
    convertCartesianToSpherical( cartesianCoordinatesTest25_, sphericalCoordinates_ );
    differences_ = sphericalCoordinates_ - expectedSphericalCoordinatesTest25_;

    if ( differences_.norm( ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCartesianToSpherical, function does not "
             << "function correctly. ( Test 25 )." << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test 26: Test conversion of: ( 5.2, -6.3, 0.0 ).
    convertCartesianToSpherical( cartesianCoordinatesTest26_, sphericalCoordinates_ );
    differences_ = sphericalCoordinates_ - expectedSphericalCoordinatesTest26_;

    if ( differences_.norm( ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCartesianToSpherical, function does not "
             << "function correctly. ( Test 26 )." << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test 27: Test conversion of: ( 0.0, 12.2, -0.9 ).
    convertCartesianToSpherical( cartesianCoordinatesTest27_, sphericalCoordinates_ );
    differences_ = sphericalCoordinates_ - expectedSphericalCoordinatesTest27_;

    if ( differences_.norm( ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The convertCartesianToSpherical, function does not "
             << "function correctly. ( Test 27 )." << endl;
        isBasicMathematicsFunctionsErroneous = true;
    }

    // Test linear interpolation from independent and dependent vectors.
    // Test 28: Test vector data with expected result of 0.0.
    // Test 29: Test vector data with expected result of -20.5

    // Declare variables.
    // Vectors of data.
    VectorXd sortedIndependentVariables( 3 );
    VectorXd associatedDependentVariables( 3 );

    // Target independent value in vector data.
    double targetIndependentVariableValue = 0.0;

    // Interpolated value.
    double interpolatedValue;

    // Initialize variables.
    sortedIndependentVariables( 0 ) = 0.0;
    sortedIndependentVariables( 1 ) = 1.0;
    sortedIndependentVariables( 2 ) = 3.0;
    associatedDependentVariables( 0 ) = -20.0;
    associatedDependentVariables( 1 ) = 20.0;
    associatedDependentVariables( 2 ) = 21.0;
    targetIndependentVariableValue = 0.5;

    // Compute interpolation.
    interpolatedValue = computeLinearInterpolation(
            sortedIndependentVariables, associatedDependentVariables,
            targetIndependentVariableValue );

    if ( abs( interpolatedValue - 0.0 ) > MACHINE_PRECISION_DOUBLES )
    {
       cerr << "The computeLinearInterpolation function for vector data does "
            << "not function correctly, as the computed value: "
            << interpolatedValue << " does not match the expected value: "
            << 0.0 << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }

    // Reinitialize vectors and target with new data.
    sortedIndependentVariables( 0 ) = 0.0;
    sortedIndependentVariables( 1 ) = 1.0;
    sortedIndependentVariables( 2 ) = 3.0;
    associatedDependentVariables( 0 ) = -20.0;
    associatedDependentVariables( 1 ) = 20.0;
    associatedDependentVariables( 2 ) = 21.0;
    targetIndependentVariableValue = 2.0;

    // Compute interpolation.
    interpolatedValue = computeLinearInterpolation(
            sortedIndependentVariables, associatedDependentVariables,
            targetIndependentVariableValue );

    if ( abs( interpolatedValue - 20.5 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeLinearInterpolation function for vector data does "
             << "not function correctly, as the computed value: "
             << interpolatedValue << " does not match the expected value: "
             << 20.5 << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }

    // Test linear interpolation with map of vectors with keys as
    // independent variable.
    // Test 30: Test map of data.

    // Declare map of data and vectors for map value.
    std::map < double, VectorXd > sortedIndepedentAndDependentVariables;
    VectorXd vectorOne( 3 );
    VectorXd vectorTwo( 3 );
    VectorXd vectorThree( 3 );
    VectorXd interpolatedVector( 3 );

    // Initialize vectors for map value.
    // Initialize first vector.
    vectorOne( 0 ) = 10.0;
    vectorOne( 1 ) = -10.0;
    vectorOne( 2 ) = 70.0;

    // Initialize second vector.
    vectorTwo( 0 ) = 20.0;
    vectorTwo( 1 ) = -5.0;
    vectorTwo( 2 ) = 80.0;

    // Initialize third vector.
    vectorThree( 0 ) = 30.0;
    vectorThree( 1 ) = 60.0;
    vectorThree( 2 ) = 90.0;

    // Set map values in map using vector data.
    sortedIndepedentAndDependentVariables[ 0.0 ] = vectorOne;
    sortedIndepedentAndDependentVariables[ 1.0 ] = vectorTwo;
    sortedIndepedentAndDependentVariables[ 2.0 ] = vectorThree;

    // Set target independent variable value for interpolation.
    targetIndependentVariableValue = 1.5;

    // Compute interpolation.
    interpolatedVector = computeLinearInterpolation(
            sortedIndepedentAndDependentVariables,
            targetIndependentVariableValue );

    if ( abs( interpolatedVector( 0 ) - 25.0 ) > MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedVector( 1 ) - 27.5 ) > MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedVector( 2 ) - 85.0 ) > MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeLinearInterpolation function for a map of "
             << "vectors, does not function correctly, as the compute vector "
             << "data: " <<  interpolatedVector << " does not match the "
             << "expected vector data: ( 25.0, 27.5, 85.0 ). " << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }


    // Test linear interpolation with map of States.
    // Test 31: Test run using three states. Interpolation between the first
    // and second, and second and third tested. An extrapolation is also
    // tested.

    // Declare variables.
    std::map < double, State* > stateMap;
    State* interpolatedState;
    CartesianPositionElements* cartesianPostitionStateOne =
            new CartesianPositionElements();
    CartesianPositionElements* cartesianPostitionStateTwo =
            new CartesianPositionElements();
    CartesianPositionElements* cartesianPostitionStateThree =
            new CartesianPositionElements();

    // Set position elements for three states.
    cartesianPostitionStateOne->setCartesianElementX( -7.0 );
    cartesianPostitionStateOne->setCartesianElementY( -3.0 );
    cartesianPostitionStateOne->setCartesianElementZ( -1.0 );

    cartesianPostitionStateTwo->setCartesianElementX( 7.0 );
    cartesianPostitionStateTwo->setCartesianElementY( 3.0 );
    cartesianPostitionStateTwo->setCartesianElementZ( 1.0 );

    cartesianPostitionStateThree->setCartesianElementX( 0.0 );
    cartesianPostitionStateThree->setCartesianElementY( 0.0 );
    cartesianPostitionStateThree->setCartesianElementZ( 0.0 );

    // Add states to the state map with key the independent variable.
    stateMap[ -2.0 ] = cartesianPostitionStateOne;
    stateMap[ 2.0 ] = cartesianPostitionStateTwo;
    stateMap[ 4.0 ] = cartesianPostitionStateThree;

    // Set target indepedent variable value.
    targetIndependentVariableValue = 0.0;

    // Compute interpolation.
    interpolatedState = computeLinearInterpolation(
            stateMap, targetIndependentVariableValue );

    if ( abs( interpolatedState->state( 0 ) - 0.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 1 ) - 0.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 2)  - 0.0 ) >
         MACHINE_PRECISION_DOUBLES )
    {
       cerr << "The computeLinearInterpolation function for a map of State "
            << "objects does not function correctly, as the computed state: "
            << interpolatedState->state << " does not match the expected "
            << "state: ( 0.0, 0.0, 0.0 )" << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }

    // Set new target and compute again.
    targetIndependentVariableValue = 3.0;

    // Compute interpolation.
    interpolatedState = computeLinearInterpolation(
            stateMap, targetIndependentVariableValue );

    if ( abs( interpolatedState->state( 0 ) - 3.5 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 1 ) - 1.5 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 2 ) - 0.5 ) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeLinearInterpolation function for a map of State "
             << "objects does not function correctly, as the computed state: "
             << interpolatedState->state << " does not match the expected "
             << "state: ( 3.5, 1.5, 0.5 )" << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }

    // Set new target and compute again.
    targetIndependentVariableValue = 6.0;

    // Compute interpolation.
    interpolatedState = computeLinearInterpolation(
            stateMap, targetIndependentVariableValue );

    if ( abs( interpolatedState->state( 0 ) + 7.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 1 ) + 3.0 ) >
         MACHINE_PRECISION_DOUBLES ||
         abs( interpolatedState->state( 2 ) + 1.0 ) >
         MACHINE_PRECISION_DOUBLES )
    {
        cerr << "The computeLinearInterpolation function for a map of State "
             << "objects does not function correctly, as the computed state: "
             << interpolatedState->state << " does not match the expected "
             << "state: ( -7.0, -3.0, -1.0 )" << endl;
       isBasicMathematicsFunctionsErroneous = true;
    }

    // Return test result.
    // If test is successful return false; if test fails, return true.
    return isBasicMathematicsFunctionsErroneous;
}

}

// End of file.
