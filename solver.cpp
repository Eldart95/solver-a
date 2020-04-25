#include "solver.hpp"
using namespace solver;
double solver::solve(RealVariable& x){
    double ans =0;
    x.rem=-x.rem;
    if(x.power>2){} // throw error
    if(x.power==2){
        if(x.rem>0) ans = sqrt(x.rem);
    }
    if(x.power==1){
        ans=x.rem/x.coef;
    }
    if(x.power<0){} //throw error.
    
    x.rem=0;
    x.coef=1;
    x.power=1;
    return ans;

    }

    RealVariable& solver::operator+(RealVariable& x,RealVariable& y){
        if(x.power==y.power) x.coef=x.coef+y.coef;
        //to be cont..
        return x;

    }
    RealVariable& solver::operator+(RealVariable& x,int y){
    x.rem+=y;
    return x;

    }
    RealVariable& solver::operator+(int y,RealVariable& x){
    x.rem+=y;
    return x;

    }

    RealVariable& solver::operator*(int x,RealVariable& y){
        y.coef = x;
        return y;
    }
    RealVariable& solver::operator*(RealVariable& x,RealVariable& y){
        //to be cont..
        return y;
    }
    RealVariable& solver::operator*(RealVariable& y,int x){
        y.coef = x;
        return y;
    }
    RealVariable& solver::operator/(RealVariable& x,double y){
        x.coef/=y;
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
    RealVariable& solver::operator-(RealVariable& x,const int y){
        x.rem=-y;
        return x;


    }
    RealVariable& solver::operator-(const int x,RealVariable& y){
        //to be cont..
        return y;
    }
    RealVariable& solver::operator-(RealVariable& x,RealVariable& y){
        //to be cont..
        return x;
    }
        
    RealVariable& solver::operator^(RealVariable& x,int y){
        x.power=y;
        return x;

    } 
    RealVariable& solver::operator==(RealVariable& x, const RealVariable& y) {
        //to be contd..
        return x;
    }
    RealVariable& solver::operator==(int x,RealVariable& y) {
        //to be contd..
        return y;
    }
    RealVariable& solver::operator==(RealVariable& x, int y) {
        y>0?x.rem-=y:x.rem+=y;
        return x;
        
    }




