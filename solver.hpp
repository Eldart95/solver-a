
#include <complex>
#include <string>
namespace solver{

    double solve(std::string a);
    
    struct RealVariable{
        double coef;
    };
    class ComplexVariable{
        std::complex<double> cv;
    };
    ////////////////////////////REAL VARIABLES OPERATORS OVERRIDE////////////////////////////
    RealVariable operator/(RealVariable x,double y){
        return x;

    }
    RealVariable operator+(RealVariable x,RealVariable y){
        return y;

    }
    RealVariable operator+(RealVariable x,double y){
    return x;

    }
    RealVariable operator+(int y,RealVariable x){
    return x;

    }

    RealVariable operator*(int x,RealVariable y){
        y.coef = x;
        return y;

    
    }
    RealVariable operator-(RealVariable x,const int y){
        return x;


    }
    RealVariable operator-(RealVariable x,RealVariable y){
        return x;


    }
    std::string operator==(const RealVariable x,const int y){
        return "";

    } 
        
    RealVariable operator^(RealVariable x,int y){
        return x;

    } 
    std::string operator==(const RealVariable x, const RealVariable y) {}

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////COMPLEX VARIABLE OPERATOR OVERRIDE//////////////////////////////////

    ComplexVariable operator*(const int x,ComplexVariable y){}

    ComplexVariable operator-(const ComplexVariable x,const int y){}

    ComplexVariable operator^(ComplexVariable x,int y){
        return x;

    } 
    std::string operator==(const ComplexVariable x,const int y){
        return "";

    }
    std::string operator==(const ComplexVariable x,const ComplexVariable y){
        return "";

    }     
    ComplexVariable operator+(ComplexVariable x,ComplexVariable y){
        return y;

    }
    ComplexVariable operator-(ComplexVariable x,ComplexVariable y){
        return y;

    }    
    ComplexVariable operator+(ComplexVariable x,const int y){
        return x;

    }
    ComplexVariable operator/(ComplexVariable x,const int y){
        return x;

    }
    ComplexVariable operator+(int y,ComplexVariable x){
        return x;

    }
    double operator+(int y,std::complex<double> x){
        return 3;

    }    
}








