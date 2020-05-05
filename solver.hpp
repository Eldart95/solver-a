#pragma once
#include <cmath>
#include <complex>
namespace solver{

    
    
    class RealVariable{
        public:
        double a=0;
        double b=1;
        double c=0;
        int power =1;

        RealVariable() =default;

            ////////////////////////////REAL VARIABLES OPERATORS OVERRIDE////////////////////////////
        //+
        friend RealVariable& operator+(double y,RealVariable& x);
        friend RealVariable& operator+(RealVariable& x,double y);
        friend RealVariable& operator+(RealVariable& x,RealVariable& y);
        //*
        friend RealVariable& operator*(double y,RealVariable& x);
        friend RealVariable& operator*(RealVariable& x, double y);
        friend RealVariable& operator*(RealVariable& x,RealVariable& y);
        ///
        friend RealVariable& operator/(RealVariable& x,double y);
        friend RealVariable& operator/(double y,RealVariable& x);
        friend RealVariable& operator/(RealVariable& x,RealVariable& y);
        //-
        friend RealVariable& operator-(RealVariable& x,double y);
        friend RealVariable& operator-(RealVariable& x,RealVariable& y);
        friend RealVariable& operator-(double y,RealVariable& x);
        //^
        friend RealVariable& operator^(RealVariable& x,double y);
        //==
        friend RealVariable& operator==(RealVariable& x,  double y); 
        friend RealVariable& operator==(RealVariable& x,RealVariable& y);
        friend RealVariable& operator==(double y,RealVariable& x);
        //
    
    };
    double solve(RealVariable& x);
    
    class ComplexVariable{
        public:
        double a=0;
        double b=1;
        std::complex<double> c=(0,0);
        int power = 1;

        ComplexVariable()=default;

        friend ComplexVariable& operator+(int y,ComplexVariable& x);
        friend ComplexVariable& operator+(ComplexVariable& x,int y);
        friend ComplexVariable& operator+(ComplexVariable& x,ComplexVariable& y);
        friend ComplexVariable& operator+(std::complex<double> y,ComplexVariable& x);
        friend ComplexVariable& operator+(ComplexVariable& x,std::complex<double> y);

        //*
        friend ComplexVariable& operator*(int y,ComplexVariable& x);
        friend ComplexVariable& operator*(ComplexVariable& x, int y);
        friend ComplexVariable& operator*(ComplexVariable& x,ComplexVariable& y);
        ///
        friend ComplexVariable& operator/(ComplexVariable& x, double y);
        friend ComplexVariable& operator/(double y,ComplexVariable& x);
        friend ComplexVariable& operator/(ComplexVariable& x,ComplexVariable& y);
        //-
        friend ComplexVariable& operator-(ComplexVariable& x,int y);
        friend ComplexVariable& operator-(ComplexVariable& x,ComplexVariable& y);
        friend ComplexVariable& operator-(int y,ComplexVariable& x);
        //^
        friend ComplexVariable& operator^(ComplexVariable& x,int y);
        //==
        friend ComplexVariable& operator==(ComplexVariable& x, int y); 
        friend ComplexVariable& operator==(ComplexVariable& x,ComplexVariable& y);
        friend ComplexVariable& operator==(int y,ComplexVariable& x);
        friend ComplexVariable& operator==(ComplexVariable& x,std::complex<double> y);
        friend ComplexVariable& operator==(std::complex<double> y,ComplexVariable& x);

    
    };
    std::complex<double> solve(ComplexVariable& x);

}








