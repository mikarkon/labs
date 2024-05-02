//
// Created by mikarkon on 22.12.22.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "address.h"
#include "iterator.h"
TEST_CASE("constructor")
{
    REQUIRE_NOTHROW(addressHouse());
    REQUIRE_NOTHROW(addressFlat());
    std::string s = "arbat";
    REQUIRE_NOTHROW(addressHouse(3, s));
    REQUIRE_NOTHROW(addressFlat(4, s, 10));
}

TEST_CASE("get")
{
    SECTION("1")
    {
        std::string s1 = "arbat";
        std::string s2 = "notarbat";
        addressHouse adH(2, s1);
        addressFlat adF(9, s2, 6);

        CHECK(adH.getNumberHouse() == 2);
        CHECK(adH.getStreet() == "arbat");
        CHECK(adF.getNumberHouse() == 9);
        CHECK(adF.getNumberFlat() == 6);
        CHECK(adF.getStreet() == "notarbat");
    }
    SECTION("2")
    {
        std::string s1 = "street1";
        std::string s2 = "anotherstreet";
        addressHouse adH(10, s1);
        addressFlat adF(2, s2, 34);

        CHECK(adH.getNumberHouse() != 2);
        CHECK(adH.getStreet() != "arbat");
        CHECK(adF.getNumberHouse() != 9);
        CHECK(adF.getNumberFlat() != 6);
        CHECK(adF.getStreet() != "notarbat");
    }
}

TEST_CASE("operator and equal")
{
    std::string s1 = "arbat";
    std::string s11 = s1;
    std::string s2 = "notarbat";
    std::string s22 = s2;
    std::string s3 = "street1";
    std::string s4 = "anotherstreet";
    addressHouse adH1(2, s1);
    addressHouse adH11(2, s11);
    addressFlat adF1(9, s2, 6);
    addressFlat adF11(9, s22, 6);
    addressHouse adH2(10, s3);
    addressFlat adF2(2, s4, 34);

    address *ptr;
    SECTION("==")
    {
        CHECK(!(adH1 == adH2));
        CHECK((adH1 == adH11));
        CHECK(!(adF1 == adF2));
        CHECK((adF1 == adF11));
    }
    SECTION("equal")
    {
        ptr = &adF2;
        CHECK(!adF1.equal(ptr));
        ptr = &adF11;
        CHECK(adF1.equal(ptr));
        ptr = &adH2;
        CHECK(!adH1.equal(ptr));
        ptr = &adH11;
        CHECK(adH1.equal(ptr));

        ptr = &adF2;
        CHECK(!adH1.equal(ptr));
        ptr = &adH2;
        CHECK(!adF1.equal(ptr));
    }
}
/*
TEST_CASE("it")
{
    arr<int> a;
    a.pushback(2);
    a.pushback(3);
    a.pushback(4);

    iterator<int> b(1, &a);
    auto c(b);
    auto d = b++;
    ++c;
    CHECK((c == b));
    CHECK((c == ++d));
}
 */