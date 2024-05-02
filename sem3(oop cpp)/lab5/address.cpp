//
// Created by mikarkon on 16.12.22.
//

#include "address.h"
#include <iostream>

address::address(int num, std::string &name) : numberHouse(num), street(name) {}

int address::getNumberHouse() const
{
    return numberHouse;
}

std::string &address::getStreet()
{
    return street;
}
std::string address::printAdr()
 {
    std::string s = "street: " + street + "  house N: " + std::to_string(numberHouse) + "\n";
    return s;
 }

//----------------------------------------------------------------------

addressFlat::addressFlat(int numH, std::string &name, int numF) : address(numH, name), numberFlat(numF) {}

bool addressFlat::operator==(addressFlat &adF)
{
    if(numberFlat == adF.numberFlat && getStreet() == adF.getStreet() && getNumberHouse() == adF.getNumberHouse())
        return true;
    return false;
}

bool addressFlat::equal(address *adr)
{
    auto *adF = dynamic_cast<addressFlat*>(adr);
    if(!adF)
        return false;
    return *this == *adF;
}

int addressFlat::getNumberFlat() const
{
    return numberFlat;
}

std::string addressFlat::printAdr()
{
    return "street: " + getStreet() + "  house N: " + std::to_string(getNumberHouse()) + "  flat N: " + std::to_string(numberFlat) + "\n";

}

//----------------------------------------------------------------------

bool addressHouse::operator==(addressHouse &adH)
{
    if(getStreet() == adH.getStreet() && getNumberHouse() == adH.getNumberHouse())
        return true;
    return false;
}

bool addressHouse::equal(address *adr)
{
    auto *adH = dynamic_cast<addressHouse*>(adr);
    if(!adH)
        return false;
    return *this == *adH;
}