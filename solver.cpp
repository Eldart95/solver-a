#include "solver.hpp"
using namespace std;
using namespace solver;
double solver::solve(RealVariable& x){
    return 1;


}

RealVariable& solver::operator+(RealVariable& x,RealVariable& y){
    return x;
}

RealVariable& solver::operator+(RealVariable& x,int y){
    
    return x;

}
RealVariable& solver::operator+(int y,RealVariable& x){

    return x;

}

RealVariable& solver::operator*(int x,RealVariable& y){
    return y;
}

RealVariable& solver::operator*(RealVariable& x,RealVariable& y){
    return y;
}

RealVariable& solver::operator*(RealVariable& y,int x){
    return y;
}
RealVariable& solver::operator/(RealVariable& x,double y){
    return x;

}
RealVariable& solver::operator/(RealVariable& x,RealVariable& y){
        //to be cont..
    return x;

}
RealVariable& solver::operator/(double x,RealVariable& y){
        //to be cont..
    return y;

    }
RealVariable& solver::operator-(RealVariable& x, int y){
    return x;

    }
RealVariable& solver::operator-(int x,RealVariable& y){
        //to be cont..
    return y;
}
RealVariable& solver::operator-(RealVariable& x,RealVariable& y){
        //to be cont..
    return x;
}
        
RealVariable& solver::operator^(RealVariable& x,int y){
    return x;

} 
RealVariable& solver::operator==(RealVariable& x, RealVariable& y) {
        //to be contd..
    return x;
}
RealVariable& solver::operator==(int x,RealVariable& y) {
        //to be contd..
    return y;
}
RealVariable& solver::operator==(RealVariable& x, int y) {

    return x;
        
}

//-----------------------------------------------------------------------------\\

std::complex<double> solver::solve(ComplexVariable& x){
    return 0;

}

ComplexVariable& solver::operator+(ComplexVariable& x,ComplexVariable& y){
    return x;
}

ComplexVariable& solver::operator+(ComplexVariable& x,int y){
    
    return x;

}
ComplexVariable& solver::operator+(int y,ComplexVariable& x){

    return x;

}
ComplexVariable& solver::operator+(std::complex<double> y,ComplexVariable& x){
    return x;
}


ComplexVariable& solver::operator+(ComplexVariable& x,std::complex<double> y){
    return x;
}

ComplexVariable& solver::operator*(int x,ComplexVariable& y){
    return y;
}

ComplexVariable& solver::operator*(ComplexVariable& x,ComplexVariable& y){
    return y;
}

ComplexVariable& solver::operator*(ComplexVariable& y,int x){
    return y;
}
ComplexVariable& solver::operator/(ComplexVariable& x,double y){
    return x;

}
ComplexVariable& solver::operator/(ComplexVariable& x,ComplexVariable& y){
        //to be cont..
    return x;

}
ComplexVariable& solver::operator/(double x,ComplexVariable& y){
        //to be cont..
    return y;

    }
ComplexVariable& solver::operator-(ComplexVariable& x, int y){
    return x;

    }
ComplexVariable& solver::operator-(int x,ComplexVariable& y){
        //to be cont..
    return y;
}
ComplexVariable& solver::operator-(ComplexVariable& x,ComplexVariable& y){
        //to be cont..
    return x;
}
        
ComplexVariable& solver::operator^(ComplexVariable& x,int y){
    return x;

} 
ComplexVariable& solver::operator==(ComplexVariable& x, ComplexVariable& y) {
        //to be contd..
    return x;
}
ComplexVariable& solver::operator==(int x,ComplexVariable& y) {
        //to be contd..
    return y;
}
ComplexVariable& solver::operator==(ComplexVariable& x, int y) {

    return x;
        
}
ComplexVariable& solver::operator==(ComplexVariable& x,std::complex<double>){

    return x;
}

ComplexVariable& solver::operator==(std::complex<double> y,ComplexVariable& x){
    return x;
}




