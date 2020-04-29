#pragma once
#include <cmath>
#include <complex>
namespace solver{

    
    
    class RealVariable{
        public:
        double a;
        int b;
        double c;

        RealVariable() =default;

            ////////////////////////////REAL VARIABLES OPERATORS OVERRIDE////////////////////////////
        //+
        friend RealVariable& operator+(int y,RealVariable& x);
        friend RealVariable& operator+(RealVariable& x,int y);
        friend RealVariable& operator+(RealVariable& x,RealVariable& y);
        //*
        friend RealVariable& operator*(int y,RealVariable& x);
        friend RealVariable& operator*(RealVariable& x, int y);
        friend RealVariable& operator*(RealVariable& x,RealVariable& y);
        ///
        friend RealVariable& operator/(RealVariable& x,double y);
        friend RealVariable& operator/(double y,RealVariable& x);
        friend RealVariable& operator/(RealVariable& x,RealVariable& y);
        //-
        friend RealVariable& operator-(RealVariable& x,int y);
        friend RealVariable& operator-(RealVariable& x,RealVariable& y);
        friend RealVariable& operator-(int y,RealVariable& x);
        //^
        friend RealVariable& operator^(RealVariable& x,int y);
        //==
        friend RealVariable& operator==(RealVariable& x,  int y); 
        friend RealVariable& operator==(RealVariable& x,RealVariable& y);
        friend RealVariable& operator==(int y,RealVariable& x);
        //
    
    };
    double solve(RealVariable& x);
    
    class ComplexVariable{
        public:
        std::complex<double> a,b,c;
        ComplexVariable()=default;

        friend ComplexVariable& operator+(int y,ComplexVariable& x);
        friend ComplexVariable& operator+(ComplexVariable& x,int y);
        friend ComplexVariable& operator+(ComplexVariable& x,ComplexVariable& y);
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
    

    
    };
    std::complex<double> solve(ComplexVariable& x);

}








