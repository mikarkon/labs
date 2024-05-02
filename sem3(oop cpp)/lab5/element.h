//
// Created by mikarkon on 17.12.22.
//

#ifndef LAB4_ELEMENT_H
#define LAB4_ELEMENT_H


#include "accommodation.h"

class element {
    bool isSettled{};
    std::shared_ptr<accommodation> accom;
public:
    element() = default;
    element(std::shared_ptr<accommodation> newAccom, bool set);
    std::shared_ptr<accommodation> &getAccom();
    void changeIsSettled();
    bool checkIsSettled() const;
    bool checkAddr(address *adr);
    std::string printEl();
};

class table{
    arr<element> arrEl;
public:
    table operator+=(element el);
    element& search(address *adr);
    bool addEl(element el);
    std::string show();
    std::string showNotSettled();
};

#endif //LAB4_ELEMENT_H
