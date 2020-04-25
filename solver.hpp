#pragma once
#include <string>
#include <cmath>
namespace solver{
    // class ComplexVariable{
    //     std::complex<double> cv;
    // };
    
    
    class RealVariable{
        public:
        double coef=1;
        int power=1;
        double rem=0;
    };
    double solve(RealVariable& x);
    
    ////////////////////////////REAL VARIABLES OPERATORS OVERRIDE////////////////////////////
    //+
    RealVariable& operator+(const int y,RealVariable& x);
    RealVariable& operator+(RealVariable& x,const int y);
    RealVariable& operator+(RealVariable& x,RealVariable& y);
    //*
    RealVariable& operator*(const int y,RealVariable& x);
    RealVariable& operator*(RealVariable& x,const int y);
    RealVariable& operator*(RealVariable& x,RealVariable& y);
    ///
    RealVariable& operator/(RealVariable& x,const double y);
    RealVariable& operator/(const double y,RealVariable& x);
    RealVariable& operator/(RealVariable& x,RealVariable& y);
    //-
    RealVariable& operator-(RealVariable& x,const int y);
    RealVariable& operator-(RealVariable& x,RealVariable& y);
    RealVariable& operator-(const int y,RealVariable& x);
    //^
    RealVariable& operator^(RealVariable& x,const int y);
    //==
    RealVariable& operator==(RealVariable& x, const int y); 
    RealVariable& operator==(RealVariable& x, const RealVariable& y);
    RealVariable& operator==(const int y,RealVariable& x);
    //
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////COMPLEX VARIABLE OPERATOR OVERRIDE//////////////////////////////////

    // double operator*(const int x,ComplexVariable y){
    //     return 1;
    // }

    // double operator-(const ComplexVariable x,const int y){
    //     return 1;
    // }

    // ComplexVariable operator^(ComplexVariable x,int y){
    //     return x;

    // } 
    // std::string operator==(const ComplexVariable x,const int y){
    //     return "";

    // }
    // std::string operator==(const ComplexVariable x,const ComplexVariable y){
    //     return "";

    // }     
    // ComplexVariable operator+(ComplexVariable x,ComplexVariable y){
    //     return y;

    // }
    // ComplexVariable operator-(ComplexVariable x,ComplexVariable y){
    //     return y;

    // }    
    // ComplexVariable operator+(ComplexVariable x,const int y){
    //     return x;

    // }
    // ComplexVariable operator/(ComplexVariable x,const int y){
    //     return x;

    // }
    // ComplexVariable operator+(int y,ComplexVariable x){
    //     return x;

    // }
    // double operator+(int y,std::complex<double> x){
    //     return 3;

    // }    
}








