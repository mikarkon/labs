//
// Created by mikarkon on 17.12.22.
//

#include "element.h"
#include <iostream>
#include <utility>
#include "iterator.h"

element::element(std::shared_ptr<accommodation> newAccom, bool set) : isSettled(set), accom(std::move(newAccom)){}

std::shared_ptr<accommodation> &element::getAccom()
{
    return accom;
}

bool element::checkIsSettled() const
{
    return isSettled;
}

void element::changeIsSettled()
{
    isSettled = !isSettled;
}

bool element::checkAddr(address *adr)
{
    return accom->getAddr()->equal(adr);
}

std::string element::printEl()
{
    std::string s = "status: " + std::to_string(isSettled) + "\n";
    s += accom->getInfoAccom();
    return s;
}

//--------------------------------------------------

table table::operator+=(element el){
    arrEl.pushback(std::move(el));
    return *this;
}

element &table::search(address *adr)
{
    for(auto & el : arrEl)
        if(el.checkAddr(adr))
            return el;
    throw std::runtime_error("no such address");
}

bool table::addEl(element el)
{
    try
    {
        search(el.getAccom()->getAddr().get());
    }
    catch (std::runtime_error &exception)
    {
        *this += el;
        return true;
    }
    return false;
}

std::string table::show()
{
    std::string s;
    for(auto & el : arrEl)
        s+= el.printEl();
    return s;
}

std::string table::showNotSettled()
{
    std::string s;
    for(auto &el : arrEl)
        if(!el.checkIsSettled())
            s+= el.printEl();
    return s;
}