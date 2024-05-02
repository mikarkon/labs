//
// Created by mikarkon on 10.10.22.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "LemBer.h"
TEST_CASE("Constructor")
{
    REQUIRE_NOTHROW(LemBer());
    REQUIRE_NOTHROW(LemBer(20));
    REQUIRE_NOTHROW(LemBer(-10));
    REQUIRE_NOTHROW(LemBer(-13.2));
}

TEST_CASE("Get f")
{
    SECTION("3.4")
    {
        LemBer f(3.4);
        CHECK(f.getF1().x == 3.4);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == -3.4);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 3.4);
    }
    SECTION("0")
    {
        LemBer f(0);
        CHECK(f.getF1().x == 0);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == 0);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 0);
    }
    SECTION("-13")
    {
        LemBer f(-13);
        CHECK(f.getF1().x == -13);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == 13);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 13);
    }
}
TEST_CASE("Set f")
{
    LemBer f;
    SECTION("0.02")
    {
        f.set(0.02);
        CHECK(f.getF1().x == 0.02);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == -0.02);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 0.02);
    }
    SECTION("-13.8")
    {
        f.set(-13.8);
        CHECK(f.getF1().x == -13.8);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == 13.8);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 13.8);
    }
    SECTION("4")
    {
        f.set(4);
        CHECK(f.getF1().x == 4);
        CHECK(f.getF1().y == 0);
        CHECK(f.getF2().x == -4);
        CHECK(f.getF2().y == 0);
        CHECK(f.getC() == 4);
    }
}

TEST_CASE("distance to center")
{
    LemBer f(4);
    SECTION("0.4")
    {
        CHECK(f.dist2CenterPS(0.4) == Approx(4.721).margin(0.001));
    }
    SECTION("-0.2")
    {
        CHECK(f.dist2CenterPS(-0.2) == Approx(5.428).margin(0.001));
    }
    SECTION("0")
    {
        CHECK(f.dist2CenterPS(0) == Approx(5.656).margin(0.001));
    }
}
TEST_CASE("radius of curvature (angle)")
{
    LemBer f(10);
    SECTION("12")
    {
        CHECK(f.radiusCurvAngle(12) == Approx(7.238).margin(0.001));
    }
    SECTION("-3")
    {
        CHECK(f.radiusCurvAngle(-3) == Approx(4.810).margin(0.001));
    }
    SECTION("0")
    {
        CHECK(f.radiusCurvAngle(0) == Approx(4.714).margin(0.001));
    }
}
TEST_CASE("radius of curvature (radius)")
{
    LemBer f(7);
    SECTION("12")
    {
        CHECK(f.radiusCurvRadius(12) == Approx(2.722).margin(0.001));
    }
    SECTION("300")
    {
        CHECK(f.radiusCurvRadius(300) == Approx(0.108).margin(0.001));
    }
    SECTION("2")
    {
        CHECK(f.radiusCurvRadius(2) == Approx(16.333).margin(0.001));
    }
}
TEST_CASE("S of sector")
{
    LemBer f(7);
    SECTION("33")
    {
        CHECK(f.sectorArea(33) == Approx(0.650).margin(0.001));
    }
    SECTION("20")
    {
        CHECK(f.sectorArea(20) == Approx(18.255).margin(0.001));
    }
    SECTION("-3")
    {
        CHECK(f.sectorArea(-3) == Approx(6.845).margin(0.001));
    }
}
TEST_CASE("S")
{
    SECTION("16")
    {
        LemBer f(16);
        CHECK(f.area() == 256);
    }
    SECTION("3")
    {
        LemBer f(3);
        CHECK(f.area() == 9);
    }
    SECTION("7")
    {
        LemBer f(7);
        CHECK(f.area() == 49);
    }
}