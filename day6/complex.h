// practicing templates, creating custom complex number type with templates to allow for doubles floats and ints to be used. 
#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Complex{
public:
  
    Complex(std::vector<T>& cmplx) : real(cmplx[0]), imaginary(cmplx[1]) {}

    std::vector<T> getValue(){
    return {real, imaginary}; 
    }

    void addition(T r, T i){
        real = real + r;
        imaginary = imaginary + i;
    }

    void subtraction(T r, T i){
        real = real - r;
        imaginary = imaginary - i;

    }

    void multiply(T r, T i){
        T newReal = (real * r) - (imaginary * i);
        imaginary = (real * i) + (imaginary * r); 
        real = newReal;
    }
    //a=real + ib=imaginary c=r + id=i
    void divide(T r, T i){
        T newReal = (real*r + imaginary*i) / (r*r + i*i); 
        imaginary = (imaginary*r - real*i) / (r*r + i*i);
        real = newReal;
    }

    
private:
    T real;
    T imaginary;

};
