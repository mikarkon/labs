//
// Created by mikarkon on 10.10.22.
//
#include <iostream>
#include <vector>
#include "LemBer.h"
#include "dialog.h"

namespace dialog
{
    void dialog(const std::vector<std::string> &msgs, int msgsAmount, int &rc)
    {
        std::string s = "";
        do
        {
            std::cout << s << std::endl;
            for(const auto &msg: msgs)
                std::cout << msg << std::endl;
            s = "wrong number";
            getNeeded<int>(std::cin, "Select", rc);
        } while(rc < 0 || rc >= msgsAmount);
    }

    void dSet(LemBer &f)
    {
        double x;
        getNeeded(std::cin, "put the \"C\"", x);
        f.set(x);
    }

    int check(LemBer &f)
    {
        if(f.getC() == -1)
        {
            std::cout<<"Для начала введите кривую.";
            return 1;
        }
        return 0;
    }

    void dGet(LemBer &f)
    {
        if(check(f)) return;
        point f1 = f.getF1();
        std::cout << "f1: x = " << f1.x << " y = " << f1.y << std::endl;
        f1 = f.getF2();
        std::cout << "f2: x = " << f1.x << " y = " << f1.y << std::endl;
        std::cout << "c = " << f.getC() << std::endl;
    }

    void dDist2CenterPS(LemBer &f)
    {
        if(check(f)) return;
        double phi;
        getNeeded(std::cin, "put the angle", phi);
        double k = f.dist2CenterPS(phi);
        if(k < 0)
            std::cout << "incorrect angle\n";
        else
            std::cout << "distance 2 center = " << k << std::endl;
    }

    void dRadiusCurvAngle(LemBer &f)
    {
        if(check(f)) return;
        double phi;
        getNeeded(std::cin, "put the angle", phi);
        std::cout << "radius of curvature (angle)= " << f.radiusCurvAngle(phi) << std::endl;
    }

    void dRadiusCurvRadius(LemBer &f)
    {
        if(check(f)) return;
        double r;
        getNeeded(std::cin, "put the radius", r);
        if(r > 0)
            std::cout << "radius of curvature (polar radius)= " << f.radiusCurvRadius(r) <<std::endl;
        std::cout << "incorrect radius";
    }

    void dSectorArea(LemBer &f)
    {
        if(check(f)) return;
        double phi;
        getNeeded(std::cin, "put the angle", phi);
        std::cout << "S of sector = " << f.sectorArea(phi) << std::endl;
    }

    void dArea(LemBer &f)
    {
        if(check(f)) return;
        std::cout << "S = " << f.area() << std::endl;
    }
}

