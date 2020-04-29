#include "solver.hpp"
#include "doctest.h"


TEST_CASE("stage 1"){
    solver::RealVariable x;
    CHECK(solver::solve(3*x==6)==2);
    CHECK(solver::solve(8*x==64)==8);
    CHECK(solver::solve(3+x==6)==3);
    CHECK(solver::solve(x-2==1)==3);
    CHECK(solver::solve(6/x==1)==6);
    
    CHECK(solver::solve(3*x+12==-6)==-6);
    CHECK(solver::solve(8*x+2==10)==1);
    CHECK(solver::solve(3+x+4+x==15)==8);
    CHECK(solver::solve(3*x-15==0)==5);
    CHECK(solver::solve(x/6==0)==0);

    CHECK(solver::solve(4*x+12==-6)==-6);
    CHECK(solver::solve(12*x+2==10)==1);
    CHECK(solver::solve(2+x+4+x==15)==8);
    CHECK(solver::solve(7*x-15==0)==5);
    CHECK(solver::solve(x/6==0)==0);


}
TEST_CASE("stage 2"){
    solver::RealVariable x;
    CHECK(solver::solve((x^2)==9)==3);
    CHECK(solver::solve((3*(x^2))==12)==2);
    CHECK(solver::solve(3*x+5==11)==2);
    CHECK(solver::solve(4*x-2==2)==1);
    CHECK(solver::solve(4*x+5-5==0)==0);
    
    CHECK(solver::solve((x^2)+4==14)==3);
    CHECK(solver::solve((3*(x^2)+5*x)==0)==0);
    CHECK(solver::solve(3*x+4*(x^2)==103)==5);
    CHECK(solver::solve(4*x==2)==0.5);
    CHECK(solver::solve(4*x==0)==0);
    
    CHECK(solver::solve((x^2)+4==12)==3);
    CHECK(solver::solve((3*(x^2)+12*x)==0)==0);
    CHECK(solver::solve(3*x+3*(x^2)==103)==5);
    CHECK(solver::solve(5*x==2)==0.5);
    CHECK(solver::solve(2*x==0)==0);

}
TEST_CASE("stage 3"){
    solver::RealVariable x;
    CHECK(solver::solve(3*(x^2)-6*x+9==0)==1);
    CHECK(solver::solve(((x^2)-4)==0)==2);
    CHECK(solver::solve((9*(x^2)-6*x-3)==0)==1);
        
    CHECK(solver::solve(3*(x^2)-5*x+9==x)==1);
    CHECK(solver::solve(((x^2)-3)==1)==2);
    CHECK(solver::solve((9*(x^2)-5*x-2)==x+1)==1);

    //CHECK(solver::solve(2*(x^2)-6*x+9==0)==(x^2));
    CHECK(solver::solve(((x^2)-4)==0)==2);
    CHECK(solver::solve((8*(x^2)-5*x-2)==(x^2)+x+1)==1);

    CHECK(solver::solve((x^2)+(x^2)+(x^2)==3)==0);

}

TEST_CASE("stage 4"){
    solver::RealVariable x;
    CHECK(solver::solve((x^2)==2*x)==0);
    CHECK(solver::solve(((x^2)-4+5*x)==3*x)==-5);
    CHECK(solver::solve((4*(x^2)+4*x)==0)==1);
        
    CHECK(solver::solve(2*(x^2)-4*x+2==0)==1);
    CHECK(solver::solve((3*(x+5))==21)==2);
    CHECK(solver::solve((9*(x-2)+5)==5)==2);
    //
    //CHECK(solver::solve(2*((x^2)+5*x)-6*x+9==0)==(x^2));
    CHECK(solver::solve(3*x*((x*5)-4)==0)==2);
    CHECK(solver::solve((8*(x^2)-7*x+(5*x+5)-2)==(x^2)+x+1)==1);

    CHECK(solver::solve(3*(x^2)+3*(x^2)+(3*(x^2))==3)==0);

}
TEST_CASE("stage 5"){
    solver::RealVariable x;
    CHECK_THROWS(solver::solve((x^2)==-2));
    CHECK_THROWS(solver::solve((x^2)==-5));
    CHECK_THROWS(solver::solve((x^2)+5*x+7==-2));
    CHECK_THROWS(solver::solve((x^2)+4*x+7==-2));
    CHECK_THROWS(solver::solve((x^5)==-2));
    CHECK_THROWS(solver::solve((x^7)==-2));
    CHECK_THROWS(solver::solve((x^0)==-2));
    CHECK_THROWS(solver::solve((x^12)==-2));
    CHECK_THROWS(solver::solve((x^2)==-4));

}


TEST_CASE("stage 1.1"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK(solver::solve((y^2) == 6)==t);
    CHECK(solver::solve((y^3) == 8)==t);
    CHECK(solver::solve(((y^3)+4*y) == 6)==t);
    CHECK(solver::solve((y^2)+5*y-4 == 6)==t);
    CHECK(solver::solve((4*y+3-2) == 3*y)==t);
    CHECK(solver::solve((y^2) == 6)==t);
    CHECK(solver::solve((y^2)+5*y-4 == 12*y)==t);
    CHECK(solver::solve((4*y+3-2) == 3*y+15)==t);
    CHECK(solver::solve((y^2) == 12*y+6)==t);
}

TEST_CASE("stage 1.2"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK(solver::solve((y^2)+5*y+12 == 5*y)==t);
    CHECK(solver::solve((y^3) == 4*y-3)==t);
    CHECK(solver::solve(((y^3)+4*y) == 3*(y^2)+26)==t);
    CHECK(solver::solve((y^2)+5*y-4 == 6*y-12)==t);
    CHECK(solver::solve((4*y+3-2) == 3*y-12)==t);
    CHECK(solver::solve((y^2) == 1)==t);
    CHECK(solver::solve((y^2)+5*y-4 == (y^2)+6*y+12)==t);
    CHECK(solver::solve((4*y+3-2) == ((3*y)^2))==t);
    CHECK(solver::solve((y^2) == 6*y)==t);


}
TEST_CASE("stage 1.3"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK_THROWS(solver::solve((y^3) == 0));
    CHECK_THROWS(solver::solve((y^12) == 0));
    CHECK_THROWS(solver::solve((y^8) == 0));
    CHECK_THROWS(solver::solve((y^4) == 0));
    CHECK_THROWS(solver::solve((y^0) == 0));
    CHECK_THROWS(solver::solve((y^3) == 0));


}
TEST_CASE("stage 1.4"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK(solver::solve((y^2)+12*y+12 == 3*y)==t);
    CHECK(solver::solve((y^2) == 2*y-13)==t);
    CHECK(solver::solve(((y^2)+4*y) == 3*(y^2)+26)==t);
    CHECK(solver::solve((y^2)+2*y-4 == 6*y-12)==t);
    CHECK(solver::solve((4*y+4-2) == 2*y-1)==t);
    CHECK(solver::solve((y^2) == 1)==t);
    CHECK(solver::solve((y^2)+5*y-4 == (y^2)+4*y+12)==t);
    CHECK(solver::solve((2*y+3-2) == ((3*y)^2))==t);
    CHECK(solver::solve((y^2) == 3*y)==t);


}

TEST_CASE("stage 1.5"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK(solver::solve((y^2)+2*y+12 == 2*y)==t);
    CHECK(solver::solve((y^2) == 4*y-13)==t);
    CHECK(solver::solve(((y^2)+2*y) == 3*(y^2)+26)==t);
    CHECK(solver::solve((y^2)+2*y-4 == 5*y-12)==t);
    CHECK(solver::solve((3*y+4-2) == 3*y-1)==t);
    CHECK(solver::solve((y^2) == 1)==t);
    CHECK(solver::solve((y^2)+5*y-4 == (y^2)+3*y+2)==t);
    CHECK(solver::solve((2*y+1-2) == ((2*y)^2))==t);
    CHECK(solver::solve((y^2) == 2*y)==t);


}

TEST_CASE("stage 1.6"){
    solver::ComplexVariable y;
    std::complex<double> t = (0,5);
    CHECK(solver::solve((y^2)+12*y+112 == 12*y)==t);
    CHECK(solver::solve((y^2) == 4*y-113)==t);
    CHECK(solver::solve(((y^2)+2*y) == 13*(y^2)+26)==t);
    CHECK(solver::solve((y^2)+2*y-4 == 15*y-12)==t);
    CHECK(solver::solve((12*y+4-2) == 12*y-1)==t);
    CHECK(solver::solve((y^2) == 1)==t);
    CHECK(solver::solve((y^2)+5*y-4 == (y^2)+3*y+2)==t);
    CHECK(solver::solve((2*y+1-2) == ((2*y)^2))==t);
    CHECK(solver::solve((y^2) == 12*y)==t);


}