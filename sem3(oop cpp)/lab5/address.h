//
// Created by mikarkon on 16.12.22.
//

#ifndef LAB4_ADDRESS_H
#define LAB4_ADDRESS_H
#include <string>

/**
 * @brief abstract class address
 */
class address {
    //! number of a house
    int numberHouse{};
    //! name of street
    std::string street;
public:
    /**
     * @brief empty constructor of class
     */
    address() = default;

    /**
     * @brief constructor of class
     * @param num number of house
     * @param name street name
     */
    address(int num, std::string& name);

    /**
     * @brief function to check if 2 addresses have same info
     * @param adr address with which to compare
     * @return result of checking, true if same, false if not
     */
    virtual bool equal(address* adr) = 0;

    /**
     * @brief number of house getter
     * @return house number
     */
    int getNumberHouse() const;

    /**
     * @brief street name getter
     * @return  street name
     */
    std::string &getStreet();

    /**
     * @brief function for output house number and street name
     * @param out output stream
     */
    virtual std::string printAdr();

    /**
     * @brief destructor of a class
     */
    ~address() = default;
};

/**
 * @brief class address of flat (child from abstract address)
 */
class addressFlat : public address{
    //! number of flat
    int numberFlat{};
public:
    /**
     * @brief empty constructor of class
     */
    addressFlat() = default;

    /**
     * @brief constructor of class
     * @param numH number of house
     * @param name name of street
     * @param numF number of flat
     */
    addressFlat(int numH, std::string& name, int numF);

    /**
     * @brief operator == to compare two flat addresses
     * @param adF flat address with which to compare
     * @return result of comprise if info is the same true, if not false
     */
    bool operator==(addressFlat &adF);

    /**
     * @brief override of equal from abstract class
     * @param adr abstract address with which to compare
     * @return result of checking, true if same info, false if not
     */
    bool equal(address* adr) override;

    /**
     * @brief override of print from abstract
     * @param out output stream
     */
    std::string printAdr() override;

    /**
     * @brief flat number getter
     * @return number of a flat
     */
    int getNumberFlat() const;
};

/**
 * @brief class address of house (child from abstract address)
 */
class addressHouse : public address{
public:
    /**
     * @brief empty constructor
     */
    addressHouse() = default;
    using address::address;

    /**
     * @brief operator == to compare two house addresses
     * @param adH house address with which to compare
     * @return result of comprise if info is the same true, if not false
     */
    bool operator==(addressHouse &adH);

    /**
     * @brief override of equal from abstract class
     * @param adr abstract address with which to compare
     * @return result of checking, true if same info, false if not
     */
    bool equal(address* adr) override;
};
#endif //LAB4_ADDRESS_H
