//
// Created by mikarkon on 16.12.22.
//

#ifndef LAB4_ACCOMMODATION_H
#define LAB4_ACCOMMODATION_H
#include "address.h"
#include "arr.h"
#include <memory>

class room{
    std::string name;
    int square{};
    std::string comment;
public:
    room() = default;
    room(std::string &nm, int sq, std::string &comment);
    int getSquareRoom() const;
    std::string getInfoRoom();
};

class building{
    int numberBuild{};
    arr<room> arrRooms;
public:
    building() = default;
    building(int num, arr<room> &arr);
    std::string getInfoBuild();
    int getSquareBuild();
};
;
class accommodation {
    int costPerSqMeter{};
    std::shared_ptr<address> adr;
public:
    accommodation() = default;
    accommodation(float cost, std::shared_ptr<address> anAdr);
    int getCostPerM() const;
    std::shared_ptr<address> getAddr();
    virtual std::string getInfoAccom() = 0;
    virtual int getSquareAccom() = 0;
    virtual std::string getType() = 0;
    int getCost();
    virtual ~accommodation() = default;
};

class flat : public accommodation{
    room arrRooms[4];
public:
    flat() = default;
    flat(float coast, std::shared_ptr<address> anAdr, room anArr[4]);
    std::string getInfoAccom() override;
    std::string getType() override;
    int getSquareAccom() override;
};

class apartments : public accommodation{
    arr<room> arrRooms;
public:
    apartments() = default;
    apartments(float cost,std::shared_ptr<address> anAdr, arr<room> anArr);
    std::string getInfoAccom() override;
    std::string getType() override;
    int getSquareAccom() override;
};

class cottage : public accommodation{
    arr<building> arrBuilds;
public:
    cottage() = default;
    cottage(float cost, std::shared_ptr<address> anAdr, arr<building> anArr);
    std::string getInfoAccom() override;
    std::string getType() override;
    int getSquareAccom() override;
};
#endif //LAB4_ACCOMMODATION_H
