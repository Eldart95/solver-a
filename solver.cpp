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
    if(x.a==0 && x.b==0) throw new Mexception();
    if(x.b==0 && x.c.real()>0 && x.power==2){
        if(x.a==1){
            return std::complex<double> (0,sqrt(x.c.real()));
        }
        else {
            x.c/=x.a;
            return std::complex<double> (0,sqrt(x.c.real()));
        }
    }
    double discriminant = x.b*x.b - 4*x.a*x.c.real();
    std::complex<double> x1;
    
    double img,real;
    if(x.power==1){
        return -x.c/x.b;
    }
    if(discriminant>=0) { 
        x1 = (-x.b + sqrt(discriminant)) / (2*x.a);
    }
    else {
        real = -x.b/(2*x.a);
        img =sqrt(-discriminant)/(2*x.a);
        std::complex<double> x2 = (real,img);
        return x2;
    }
    return x1;

}

ComplexVariable& solver::operator+(ComplexVariable& x,ComplexVariable& y){
    ComplexVariable* temp = new ComplexVariable();
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

ComplexVariable& solver::operator+(ComplexVariable& x,int y){
    return (y+x);

}
ComplexVariable& solver::operator+(int y,ComplexVariable& x){
    ComplexVariable* temp = new ComplexVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c.real()+y;
    temp->power=x.power;
    return *temp;

}
ComplexVariable& solver::operator+(std::complex<double> y,ComplexVariable& x){
    ComplexVariable* temp = new ComplexVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c+y;
    temp->power=x.power;
    return *temp;
}


ComplexVariable& solver::operator+(ComplexVariable& x,std::complex<double> y){
    return (y+x);
}

ComplexVariable& solver::operator*(int x,ComplexVariable& y){
    ComplexVariable* temp =new ComplexVariable();
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

ComplexVariable& solver::operator*(ComplexVariable& x,ComplexVariable& y){
    return x;
}

ComplexVariable& solver::operator*(ComplexVariable& y,int x){
    return x*y;
}
ComplexVariable& solver::operator/(ComplexVariable& x,double y){
    if(y==0) throw new Mexception();
    ComplexVariable* temp= new ComplexVariable();
    temp->a=x.a/y;
    temp->b=x.b/y;
    temp->power=x.power;
    temp->c=x.c/y;
    return *temp;

}
ComplexVariable& solver::operator/(ComplexVariable& x,ComplexVariable& y){
    
    return x;

}
ComplexVariable& solver::operator/(double y,ComplexVariable& x){
    ComplexVariable* temp = new ComplexVariable();
    temp->a=y/x.a;
    temp->b=y/x.b;
    temp->power=x.power;
    temp->c=y/x.c;
    return *temp;

    }
ComplexVariable& solver::operator-(ComplexVariable& x, int y){
    ComplexVariable* temp = new ComplexVariable();
    temp->a=x.a;
    temp->b=x.b;
    temp->c=x.c.real()-y;
    temp->power=x.power;
    return *temp;

    }
ComplexVariable& solver::operator-(int x,ComplexVariable& y){
    ComplexVariable* temp = new ComplexVariable();
    temp->a=y.a;
    temp->b=y.b;
    temp->power=y.power;
    temp->c=-y.c.real()-x;
    return *temp;
}

ComplexVariable& solver::operator-(ComplexVariable& x,ComplexVariable& y){
    ComplexVariable* temp = new ComplexVariable();
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
        
ComplexVariable& solver::operator^(ComplexVariable& x,int y){
    if(y<1 || y>2) throw new Mexception();
    ComplexVariable* temp = new ComplexVariable();
    temp->a=1;
    temp->b=0;
    temp->power=2;
    temp->c=x.c;
    return *temp;


} 
ComplexVariable& solver::operator==(ComplexVariable& x, ComplexVariable& y) {
    ComplexVariable* temp = new ComplexVariable();
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
    temp->c=x.c-y.c;

    return *temp;
}
ComplexVariable& solver::operator==(int x,ComplexVariable& y) {
    return y==x;
}
ComplexVariable& solver::operator==(ComplexVariable& x, int y) {
    ComplexVariable* temp= new ComplexVariable();
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
ComplexVariable& solver::operator==(ComplexVariable& x,std::complex<double> y){
    return x;
}

ComplexVariable& solver::operator==(std::complex<double> y,ComplexVariable& x){
    return x==y;
}




