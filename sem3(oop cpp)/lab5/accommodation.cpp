//
// Created by mikarkon on 16.12.22.
//

#include "accommodation.h"
#include <cmath>
#include <iostream>
#include <utility>
#include "iterator.h"
#include <cmath>
//---------------------ROOM---------------------

room::room(std::string &nm, int sq, std::string &com) : name(nm), square(sq), comment(com) {}

int room::getSquareRoom() const {
    return square;
}

std::string room::getInfoRoom() {
    return "name: " + name + "  comment: " + comment + "\n";
}

//---------------------BUILDING---------------------

building::building(int num, arr<room> &arr) : numberBuild(num), arrRooms(arr) {}

std::string building::getInfoBuild() {
    std::string s = "square: " + std::to_string(getSquareBuild()) + "\n";
    s +="building N: " + std::to_string(numberBuild) + "  amount of rooms: " + std::to_string(arrRooms.getAmount()) + "\n";
    for (int i = 0; i < arrRooms.getAmount(); i++)
        s += arrRooms[i].getInfoRoom();
    return s;
}

int building::getSquareBuild() {
    int s = 0;
    for (int i = 0; i < arrRooms.getAmount(); i++)
        s += arrRooms[i].getSquareRoom();
    return s;
}


//---------------------ACCOMMODATION---------------------

accommodation::accommodation(float cost,std::shared_ptr<address> anAdr) : costPerSqMeter(cost), adr(std::move(anAdr)) {}

int accommodation::getCostPerM() const {
    return costPerSqMeter;
}

int accommodation::getCost() {
    return getCostPerM() * getSquareAccom();
}

std::shared_ptr<address> accommodation::getAddr() {
    return adr;
}

//---------------------FLAT---------------------

flat::flat(float cost, std::shared_ptr<address> anAdr, room anArr[4]) : accommodation(cost, std::move(anAdr)) {
    for (int i = 0; i < 4; i++)
        arrRooms[i] = anArr[i];
}

std::string flat::getInfoAccom() {

    std::string s = getType() + "\n" + getAddr()->printAdr() + "square: " + std::to_string(getSquareAccom()) + " cost: " + std::to_string((getCost())) + "\n";
    for (auto &arrRoom: arrRooms)
        s += arrRoom.getInfoRoom();
    return s;
}

std::string flat::getType() {
    return "flat";
}

int flat::getSquareAccom() {
    int s = 0;
    for (auto &arrRoom: arrRooms)
        s += arrRoom.getSquareRoom();
    return s;
}


//---------------------APARTMENTS---------------------

apartments::apartments(float cost, std::shared_ptr<address> anAdr, arr<room> anArr) : accommodation(cost, std::move(anAdr)), arrRooms(std::move(anArr)) {}

std::string apartments::getInfoAccom() {
    std::string s = getType() + "\n" + getAddr()->printAdr() + "square: " + std::to_string(getSquareAccom()) + " cost: " + std::to_string((getCost())) + "\n";
    for (auto &arrRoom: arrRooms)
        s += arrRoom.getInfoRoom();
    return s;
}

std::string apartments::getType() {
    return "apartments" ;
}

int apartments::getSquareAccom() {
    int s = 0;
    for (auto &arrRoom: arrRooms)
        s += arrRoom.getSquareRoom();
    return s;
}

//---------------------COTTAGE---------------------

cottage::cottage(float cost, std::shared_ptr<address> anAdr, arr<building> anArr) : accommodation(cost, std::move(anAdr)), arrBuilds(std::move(anArr)) {}

std::string cottage::getInfoAccom() {
    std::string s = getType() + "\n" + getAddr()->printAdr() + "square: " + std::to_string(getSquareAccom()) + " cost: " + std::to_string((getCost())) + "\n";
    for (auto &arrBuild: arrBuilds)
        s += arrBuild.getInfoBuild();
    return s;
}

std::string cottage::getType() {
    return "cottage";
}

int cottage::getSquareAccom() {
    int s = 0;
    for (auto &arrBuild: arrBuilds)
        s += arrBuild.getSquareBuild();
    return s;
}
