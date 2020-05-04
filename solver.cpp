#include "solver.hpp"
using namespace std;
using namespace solver;


struct Mexception : std::exception {
        const char* what() const throw() {
            const char* ex = "Error,illegal operation";
            return ex;
            }
};

double solver::solve(RealVariable& x){
    if(x.a==0 && x.b==0) throw new Mexception();
    double discriminant = x.b*x.b - 4*x.a*x.c;
    double x1;
    if(x.power==1){
        return -x.c/x.b;
    }
    if(discriminant>=0) { 
        x1 = (-x.b + sqrt(discriminant)) / (2*x.a);
    }
    else {
        throw new Mexception();
    }
    return x1;
}

RealVariable& solver::operator+(RealVariable& x,RealVariable& y){
    RealVariable* temp = new RealVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c;
    temp->power=x.power;
    if(temp->power==y.power){
        temp->a+=y.a;
    }
    temp->b+=y.b;
    temp->c+=y.c;
    return *temp;
}

RealVariable& solver::operator+(RealVariable& x,double y){
    RealVariable* temp=new RealVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->power=x.power;
    temp->c=x.c+y;
    return *temp;

}
RealVariable& solver::operator+(double y,RealVariable& x){
    return x+y;

}

RealVariable& solver::operator*(double x,RealVariable& y){
    RealVariable* temp =new RealVariable();
    temp->a=y.a;
    temp->b=y.b;
    temp->power=y.power;
    temp->c=y.c;
    
    if(y.power==2) {
        if(y.a==1){
            temp->a=x;
        }
        else y.a*=x;
    }
    else if(y.b==1){
        temp->b=x;
    }
    else {
        temp->b+=x;
    }

    return *temp;

}

RealVariable& solver::operator*(RealVariable& x,RealVariable& y){
    return y;
}

RealVariable& solver::operator*(RealVariable& y,double x){
    return (x*y);
}
RealVariable& solver::operator/(RealVariable& x,double y){
    if(y==0) throw new Mexception();
    RealVariable* temp= new RealVariable();
    temp->a=x.a/y;
    temp->b=x.b/y;
    temp->power=x.power;
    temp->c=x.c/y;
    return *temp;

}
RealVariable& solver::operator/(RealVariable& x,RealVariable& y){
    //fiction.
    return x;

}
RealVariable& solver::operator/(double y,RealVariable& x){
    RealVariable* temp = new RealVariable();
    temp->a=y/x.a;
    temp->b=y/x.b;
    temp->power=x.power;
    temp->c=y/x.c;
    return *temp;

    }
RealVariable& solver::operator-(RealVariable& x, double y){
    return (y-x);
    }
RealVariable& solver::operator-(double x,RealVariable& y){
    RealVariable* temp = new RealVariable();
    temp->a=y.a;
    temp->b=y.b;
    temp->power=y.power;
    temp->c=-y.c-x;
    return *temp;
}

RealVariable& solver::operator-(RealVariable& x,RealVariable& y){
    RealVariable* temp = new RealVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c;
    temp->power=x.power;
    if(x.power==y.power){
        temp->a-=y.a;
    }
    temp->b-=y.b;
    temp->c-=y.c;
    return *temp;

}
        
RealVariable& solver::operator^(RealVariable& x,double y){
    if(y<1 || y>2) throw new Mexception();
    RealVariable* temp = new RealVariable();
    temp->a=1;
    temp->b=0;
    temp->power=2;
    temp->c=x.c;
    return *temp;

} 
RealVariable& solver::operator==(RealVariable& x, RealVariable& y) {
    RealVariable* temp = new RealVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c;
    temp->power=x.power;
    if(y.power==x.power){
        if(y.a>0){
            temp->a-=y.a;
        }
        else {
            temp->a+=y.a;
        }
    }
    if(y.b>0){
        temp->b-=y.b;
    }
    else {
        temp->b+=-y.b;
    }
    if(y.c>0){
        temp->c-=y.c;
    }
    else{
        temp->c+=-y.c;
    }

    return *temp;
}
RealVariable& solver::operator==(double x,RealVariable& y) {
    return (y==x);
}
RealVariable& solver::operator==(RealVariable& x, double y) {
    RealVariable* temp= new RealVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->power=x.power;
    temp->c=x.c;
    if(y>0){
        temp->c-=y;
    }
    else {
        temp->c+=-y;
    }
    return *temp;
        
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




