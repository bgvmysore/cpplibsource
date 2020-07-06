/***************************************************
**             COMPLEX NUMBER HEADER              **
**     Author:bgvmysore   Date: 04-July-2020      **
**     github: https://github.com/bgvmysore/      **
***************************************************/

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <utility>

namespace bgv {

    //Useful constants
    static float const constant_pi = 3.141592f;
    static float const constant_e  = 2.718281f;


    class Complex{

    //private variables
    private:
        float m_re, m_im;

    //static functions
    public:
        static Complex const iota                  (                               );
        static Complex       constructFromPolar_rad(float magnitude, float radAngle);
        static Complex       constructFromPolar_deg(float magnitude, float degAngle);

    //private functions
    protected:
        void setRe     (float Real                 );
        void setIm     (float Imaginary            );
        void setComplex(float Real, float Imaginary);

    //constructors
    public:
        Complex(                           );
        Complex(float Real, float Imaginary);
        Complex(Complex const& other       );

    //operators
    public:
        Complex add     (Complex const& another) const;
        Complex subtract(Complex const& another) const;
        Complex multiply(Complex const& another) const;
        Complex divide  (Complex const& another) const;
        Complex scale   (float A               ) const;

    //operator overloading
    public:
        Complex operator +(Complex const& another);
        Complex operator -(Complex const& another);
        Complex operator *(Complex const& another);
        Complex operator /(Complex const& another);
        bool    operator==(Complex const& another);

    //const functions
    public:
        float       getRe        () const;
        float       getIm        () const;
        float       Magnitude    () const;
        double      dMagnitude   () const;
        float       radArgument  () const;
        float       degArgument  () const;
        void        println      () const;
        std::string str          () const;
        Complex     getConjugate () const;
        
    //pair functions
    public:
        std::pair<float, float> getComplexPair  () const;
        std::pair<float, float> getPolarPair_deg() const;
        std::pair<float, float> getPolarPair_rad() const;

    //deconstructor//
    public:
        ~Complex();

    };


}
#endif // COMPLEX_HPP