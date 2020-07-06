#include "Complex.hpp"

namespace bgv{

    /*******************************CONSTRUCTORS*************************************/
    Complex::Complex():m_re(0), m_im(0) {}

    Complex::Complex(float a, float b):m_re(a), m_im(b) {}

    Complex::Complex(Complex const& other) :m_re( other.getRe() ), m_im( other.getIm() ){}
    /**************************************************************///end constructors

    /**********************************SETTERS**************************************/
    void Complex::setRe(float A){
        this->m_re = A;
        }

    void Complex::setIm(float B){
        this->m_im = B;
        }

    void Complex::setComplex(float A, float B){
        this->setRe(A);
        this->setIm(B);
        }
    /******************************************************************///end setters

    /********************************STATIC FUNT************************************/
    Complex const Complex::iota(){
        return Complex(0,1);
        }

    Complex Complex::constructFromPolar_rad(float magnitude, float radAngle){
        float tmp_re = magnitude*cosf(radAngle);
        float tmp_im = magnitude*sinf(radAngle);
        return Complex(tmp_re, tmp_im);
        }

    Complex Complex::constructFromPolar_deg(float magnitude, float degAngle){
        float tmp_re = magnitude*cosf(degAngle*bgv::constant_pi/180);
        float tmp_im = magnitude*sinf(degAngle*bgv::constant_pi/180);
        return Complex(tmp_re, tmp_im);
        }
    /*********************************************************///end static functions

    /********************************OPERATORS**************************************/
    Complex Complex::add(Complex const& another) const{
         return Complex ( this->getRe() + another.getRe(), 
                         this->getIm() + another.getIm() 
                        );
        }

    Complex Complex::subtract(Complex const& another) const{
        return Complex ( this->getRe() - another.getRe(), 
                         this->getIm() - another.getIm() 
                        );
        }

    Complex Complex::multiply(Complex const& another) const{
        return Complex (
        ( ( this->getRe() * another.getRe() ) - ( this->getIm() * another.getIm() ) ),
        ( ( this->getRe() * another.getIm() ) + ( this->getIm() * another.getRe() ) )
        );
        }

    Complex Complex::divide(Complex const& another) const{
         return Complex (
        ( ( this->getRe() * another.getRe() ) - ( this->getIm() * -1 * another.getIm() ) ) 
        / ( (another.getRe() * another.getRe() ) + ( another.getIm() * another.getIm() ) ),
        
        ( ( this->getRe() * -1 * another.getIm() ) + ( this->getIm() * another.getRe() ) ) 
        / ( (another.getRe() * another.getRe() ) + ( another.getIm() * another.getIm() ) )
        );
        }

    Complex Complex::scale(float A) const{
      return Complex(
      this->getRe()*A,
      this->getIm()*A
      );
    }
    /**************************************************************///end operators
    
    /***************************OPERATOR OVERLOADING*********************************/
    Complex Complex::operator+(Complex const& another){
        return this->add(another);
        }
    
    Complex Complex::operator-(Complex const& another){
        return this->subtract(another);
        }

    Complex Complex::operator*(Complex const& another){
        return this->multiply(another);
        }
    
    Complex Complex::operator/(Complex const& another){
        return this->divide(another);
        }
    
    bool Complex::operator==(Complex const& another){
        if( this->getRe() == another.getRe() && this->getIm() == another.getIm() )
            return true;
        else
            return false;
        }
    /******************************************************///end operator overloading
    
    /*******************************CONST FUNCTS*************************************/
    float Complex::getRe() const{
        return this->m_re;
        }

    float Complex::getIm() const{
        return this->m_im;
        }

    float Complex::Magnitude() const{
        return sqrtf( powf(this->getRe(),2) + powf(this->getIm(),2) );
        }
    

    double Complex::dMagnitude() const{
        return sqrt( pow(this->getRe(),2) + pow(this->getIm(),2) );
        }
    
    float Complex::radArgument()const{
        return atan2f(this->getIm(),this->getRe());
        }
    
    float Complex::degArgument()const{
        return 180*atan2f(this->getIm(),this->getRe())/bgv::constant_pi;
        }

    void Complex::println() const{
       std::cout << this->getRe() << " + i(" << this->getIm() << ")" << std::endl;
        }

    std::string Complex::str() const{
        std::stringstream restr, imstr;
        restr << getRe();
        imstr << getIm();
        return restr.str() + " + i(" + imstr.str() + ")";
        }
    
    Complex Complex::getConjugate() const{
        return Complex( this->getRe(), -1*this->getIm() );
        }
    
    std::pair<float, float> Complex::getComplexPair() const{
        return std::pair<float, float>( this->getRe(), this->getIm() );
        }
    
    std::pair<float, float> Complex::getPolarPair_deg() const{
        return std::pair<float, float>( this->Magnitude(), this->degArgument() );
        }
    
    std::pair<float, float> Complex::getPolarPair_rad() const{
        return std::pair<float, float>( this->Magnitude(), this->radArgument() );
        }
    /***********************************************************///end const funtions
    
    /*******************************DESTRUCTORS**************************************/
    Complex::~Complex(){}
    /****************************************************************///end destructor
}