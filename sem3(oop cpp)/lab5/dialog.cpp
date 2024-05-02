//
// Created by mikarkon on 18.12.22.
//


#include <iostream>
#include <memory>

#include "dialog.h"
#include "iterator.h"


int choose()
{
    int n;
    std::string s;
    do {
        std::cout << s << std::endl;
        getNeeded(std::cin, "choose type of accommodation (0 - flat, 1 - apartments, 2 - building)\n", n);
        s = "wrong choice";
    } while (n > 2);
    return n;
}

addressFlat createAdrF(std::istream& in)
{
    int nH,nF;
    std::string st;
    getNeeded(in, "put house N ", nH);
    getNeeded(in, "put flat N ", nF);
    getNeeded(in, "put street name ", st);
    return {nH, st, nF};
}

addressHouse createAdrH(std::istream& in)
{
    int nH;
    std::string st;
    getNeeded(in, "put house N ", nH);
    getNeeded(in, "put street name ", st);
    return {nH, st};
}

room createRoom(std::istream& in)
{
    std::string name, comment;
    float sq;
    getNeeded(in, "put name of room ", name);
    getNeeded(in, "put square of room ", sq);
    getNeeded(in, "put comment", comment);
    return {name, sq, comment};
}

float createCost(std::istream& in)
{
    float c;
    getNeeded(in, "put cost/m^2 ", c);
    return c;
}

flat createFlat(std::istream& in)
{
    room arR[4];
    for(auto & i : arR)
        i = createRoom(in);
    std::shared_ptr<address> ptr(new addressFlat(createAdrF(in)));
    return {createCost(in), ptr, arR};
}

apartments createApartments(std::istream& in)
{
    int n;
    getNeeded(in, "put amount of rooms ", n);
    arr<room> arR(n);
    for(auto & i: arR)
        i = createRoom(in);
    std::shared_ptr<address> ptr(new addressFlat(createAdrF(in)));
    return {createCost(in), ptr, arR};
}

cottage createCottage(std::istream& in)
{
    int n;
    getNeeded(in, "put amount of buildings", n);
    arr<building> arB(n);
    for(auto & i: arB)
    {
        int num;
        getNeeded(in, "put number of building", num);
        int m;
        getNeeded(in, "put amount of rooms ", m);
        arr<room> arR(m);
        for(auto & j: arR)
            j = createRoom(in);
        i = building(num, arR);
    }
    std::shared_ptr<address> ptr(new addressHouse(createAdrH(in)));
    return {createCost(in), ptr, arB};
}

namespace dialog
{
    void dialog(const std::vector<std::string> &msgs, int msgsAmount, int &rc)
    {
        std::string s;
        do {
            std::cout << s << std::endl;
            for (const auto &msg: msgs)
                std::cout << msg << std::endl;
            s = "wrong number";
            getNeeded(std::cin, "Select", rc);
        } while (rc < 0 || rc >= msgsAmount);
    }


    void dAddAccommodation(table& tbl, std::ostream &out)
    {
        std::cout << "Input accommodation\n";
        int c = choose();

        std::shared_ptr<accommodation> ptr;

        flat a;
        apartments b;
        cottage d;
        if(c == 0) {
             ptr = std::shared_ptr<accommodation>(new flat(createFlat(std::cin)));
        }
        else if(c == 1) {
             ptr = std::shared_ptr<accommodation>(new apartments(createApartments(std::cin)));
        }
        else {
            ptr = std::shared_ptr<accommodation>(new cottage(createCottage(std::cin)));
        }
        tbl.addEl(element(ptr, false));
    }

    /*void dAddAccommodation(table& tbl)
    {
        std::cout << "Input accommodation\n";
        int c = choose();
        accommodation *ptr;
        flat a;
        apartments b;
        cottage d;
        if(c == 0) {
             a = createFlat(std::cin);
             ptr = &a;
        }
        else if(c == 1) {
             b = createApartments(std::cin);
             ptr = &b;
        }
        else {
            d = createCottage(std::cin);
             ptr = &d;
        }
        element el(ptr, false);
        tbl.addEl(el);
    }*/

    void dRegIn(table& tbl, std::ostream &out)
    {
        int c = choose();
        address* ptr;
        addressFlat adrF;
        addressHouse adrH;
        if(c != 2) {
            adrF = createAdrF(std::cin);
            ptr = &adrF;
        }
        else {
            adrH = createAdrH(std::cin);
            ptr = &adrH;
        }
        try
        {
            element &el = tbl.search(ptr);
            if(!el.checkIsSettled())
                el.changeIsSettled();
        }
        catch (std::runtime_error &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    void dRegOut(table& tbl, std::ostream &out)
    {
        int c = choose();
        address* ptr;
        addressFlat adrF;
        addressHouse adrH;
        if(c != 2) {
            adrF = createAdrF(std::cin);
            ptr = &adrF;
        }
        else {
            adrH = createAdrH(std::cin);
            ptr = &adrH;
        }
        try
        {
            element &el = tbl.search(ptr);
            if(el.checkIsSettled())
                el.changeIsSettled();
        }
        catch (std::runtime_error &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    void dSearchAdr(table& tbl, std::ostream &out)
    {
        int c = choose();
        address* ptr;
        addressFlat adrF;
        addressHouse adrH;
        if(c != 2) {
            adrF = createAdrF(std::cin);
            ptr = &adrF;
        }
        else {
            adrH = createAdrH(std::cin);
            ptr = &adrH;
        }
        try
        {
            element &el = tbl.search(ptr);
            std::cout << el.printEl();
        }
        catch (std::runtime_error &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    void dShow(table& tbl, std::ostream &out)
    {
        out << tbl.show();
    }

    void dShowNotSettled(table& tbl, std::ostream &out)
    {
        out << tbl.showNotSettled();
    }
}