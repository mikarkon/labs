//
// Created by mikarkon on 18.12.22.
//

#ifndef LAB4_DIALOG_H
#define LAB4_DIALOG_H
#include <iostream>
#include <limits>
#include <vector>
#include "element.h"

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
            throw std::invalid_argument("End of file is discovered!");
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

template<typename T>
void getNeededOnce(std::istream& in, T &val)
{
    in >> val;
    if (in.eof() || in.bad())
    {
        throw std::invalid_argument("End of file is discovered!");
    }
    else if (!in.good())
    {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("incorrect insert");
    }
}

const std::vector<std::string> msgs
        {
            "0. Выход",
            "1. Добавить жилье",
            "2. Зарегистрировать заселение",
            "3. Зарегестрировать выселение",
            "4. Найти жилье по адресу",
            "5. Показать все жилье",
            "6. Показать свободное жилье"
        };

const int msgsAmount = msgs.size();

namespace dialog
{
    void dialog(const std::vector<std::string> &msgs, int msgsAmount,int &rc);
    void dAddAccommodation(table& tbl, std::ostream &out);
    void dRegIn(table& tbl, std::ostream &out);
    void dRegOut(table& tbl, std::ostream &out);
    void dSearchAdr(table& tbl, std::ostream &out);
    void dShow(table& tbl, std::ostream &out);
    void dShowNotSettled(table& tbl, std::ostream &out);
    static void (*funcArr[])(table &tbl, std::ostream &out) ={
            nullptr,
            dAddAccommodation,
            dRegIn,
            dRegOut,
            dSearchAdr,
            dShow,
            dShowNotSettled
    };
}


#endif //LAB4_DIALOG_H
