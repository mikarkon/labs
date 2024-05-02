//
// Created by mikarkon on 09.10.22.
//

#include "LemBer.h"
//#include <iostream>
#include <cmath>

double getLength(point a, point b)
{
    double x = b.x - a.x;
    double y = b.y - a.y;
    return (sqrt(x*x + y*y));
}

LemBer::LemBer(double x) : f1(x), f2(-x), c(fabs(x)) {}
LemBer::LemBer(double x, double y) : f1(x), f2(x), c(y){}

void LemBer::set(double x)
{
    f1.x = x; f1.y = 0;
    f2.x = -x; f2.y = 0;
    c = fabs(x);
}

point LemBer::getF1()const
{
    return f1;
}
point LemBer::getF2()const
{
    return f2;
}
double LemBer::getC()const
{
    return c;
}

int LemBer::checkPoint(point m)const
{
    double mf1 = getLength(f1, m);
    double mf2 = getLength(f2, m);
    return mf1*mf2 != c*c;
    if(mf1 * mf2 == c*c)
        return 0;
    return 1;
}

double LemBer::angle(point m)const
{
    if(LemBer::checkPoint(m))
        return -1;
    if(m.x == 0 && m.y == 0)
        return -2;
    return atan(m.y/m.x);
}

double LemBer::dist2CenterPS(double phi)const
{
    double cosine = cos(2 * phi);
    if(cosine > 0)
        return sqrt(2*c*c*cosine);
    else
        return -1;
}

double LemBer::radiusCurvAngle(double phi)const
{
    return (c * sqrt(2/cos(2*phi)) / 3);
}

double LemBer::radiusCurvRadius(double r)const
{
    return (2*c*c/3/r);
}

double LemBer::sectorArea(double phi) const
{
    return fabs(c*c*sin(2*phi)/2);
}

double LemBer::area()const
{
    return c*c;
}