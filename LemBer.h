//
// Created by mikarkon on 09.10.22.
//

#ifndef UNTITLED_LEMBER_H
#define UNTITLED_LEMBER_H

struct point
{
    double x,y;
    point() = default;
    explicit point(double x_) : x(x_), y(0){}
};

double getLength(point a, point b);

class LemBer{
private:
    point f1,f2;
    double c;
public:
    LemBer() = default;
    LemBer(double x);
    LemBer(double x, double y);
    void set(double x);
    point getF1()const;
    point getF2()const;
    double getC()const;
    int checkPoint(point m)const;
    double angle(point m)const;
    double dist2CenterPS(double phi)const;
    double radiusCurvAngle(double phi)const;
    double radiusCurvRadius(double r)const;
    double sectorArea(double phi)const;
    double area()const;
    ~LemBer() = default;
};


#endif //UNTITLED_LEMBER_H
