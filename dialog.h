//
// Created by mikarkon on 10.10.22.
//

#ifndef UNTITLED_DIALOG_H
#define UNTITLED_DIALOG_H
#include <iostream>
    #include <limits>
#include <vector>
#include "LemBer.h"

template<typename T>
void getNeeded(std::istream &in, const char *prompt, T &var)
{
    std::cout << prompt << std::endl;
    int i = 0;
    while(i++ < 1000)
    {
        in >> var;
        if (in.eof() || in.bad())
        {
            throw std::runtime_error("End of file is discovered!");
        }
        else if (!in.good())
        {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Try again\n";
        }
        else
            return;
    }
    throw std::runtime_error("2 much tries :(");
}

const std::vector<std::string> msgs
{
        "0) Завершить программу",
        "1) Вывод кривой.",
        "2) Ввод кривой.",
        "3) Вернуть расстояние до центра в полярной системе координат в зависимости от угла для точки принадлежащей лемнискате.",
        "4) Вернуть радиуса кривизны в зависимости от угла полярного радиуса.",
        "5) Вернуть радиуса кривизны в зависимости от длины полярного радиуса.",
        "6) Вернуть площадь полярного сектора лемнискаты в зависимости от угла полярного радиуса.",
        "7) Вернуть площадь лемнискаты."

};

const size_t msgsAmount = msgs.size();

namespace dialog
{
    void dialog(const std::vector<std::string> &msgs, int msgsAmount,int &rc);
    void dGet(LemBer &f);
    void dSet(LemBer &f);
    void dDist2CenterPS(LemBer &f);
    void dRadiusCurvAngle(LemBer &f);
    void dRadiusCurvRadius(LemBer &f);
    void dSectorArea(LemBer &f);
    void dArea(LemBer &f);
    static void (*funcArr[])(LemBer &)  = {
            nullptr,                   // 0
            dialog::dGet,
            dialog::dSet,
            dialog::dDist2CenterPS,
            dialog::dRadiusCurvAngle,
            dialog::dRadiusCurvRadius,
            dialog::dSectorArea,
            dialog::dArea,
    };
}


#endif //UNTITLED_DIALOG_H
