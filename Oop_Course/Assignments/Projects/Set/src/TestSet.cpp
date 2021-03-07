//#define DEBUG_MODE
#ifdef DEBUG_MODE
#include "../include/Set.h"

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

SCENARIO("Elements can be inserted and removed from the set", "[set]") {
    GIVEN("An empty set") {

        Set s;

        WHEN("Same elements are inserted") {
            s.insert(5);
            s.insert(5);
            s.insert(5);
            s.insert(3);
            s.insert(3);
            THEN("There is not duplicate") {
                REQUIRE(s.getSum() == 8);
            }
        }

        s.insert(9);
        s.insert(7);
        s.insert(8);
        s.insert(4);
        s.insert(5);
        s.remove_by_element(9);
        WHEN("The element is removed by element") {
            
            THEN("The element is removed from the set") {
                CHECK_FALSE(s.isMember(9));
            }
        }
        WHEN("The element is removed by index") {
            s.remove_by_index(2); // 7 is removed
            THEN("The element is removed from the set") {
                CHECK_FALSE(s.isMember(7));
            }
        }

        WHEN("Remove an element by index while index out of the set size") {
            THEN("The exception is thrown") {
                CHECK_THROWS(s.remove_by_index(7));
            }
        }

        WHEN("Remove non-existing element from the set") {
            THEN("The exception is thrown") {
                CHECK_THROWS(s.remove_by_element(22));
            }
        }
    }
}

TEST_CASE("Checking the bool methods of the set") {

    Set a;
    SECTION("Method isEmpty()") {
        CHECK_FALSE(!a.isEmpty());
        a.insert(8);
        CHECK_FALSE(a.isEmpty());
    }
    a.insert(7);
    a.insert(9);
    SECTION("Method isMember()") {
        CHECK_FALSE(!a.isMember(7));
        a.remove_by_element(7);
        CHECK_FALSE(a.isMember(7));
    }
}

TEST_CASE("Checking the other methods of the set(getSum, random, print)") {
    
    Set a;
    SECTION("Method getSum()") {

        a.insert(1);
        a.insert(2);
        a.insert(3);
        a.insert(4);
        a.insert(5);
        CHECK(a.getSum() == 15);

        a.remove_by_element(5);
        CHECK(a.getSum() == 10);

        a.remove_by_element(1);
        a.remove_by_element(2);
        a.remove_by_element(3);
        a.remove_by_element(4);
        CHECK(a.getSum() == 0);
    }

    SECTION("Method random()") {
        CHECK_THROWS(a.random());
        a.insert(7);
        a.insert(2);
        a.insert(9);
        a.insert(1);
        a.insert(5);
        REQUIRE(a.isMember(a.random()));
        a.remove_by_element(9);
        REQUIRE(a.isMember(a.random()));
        REQUIRE(a.isMember(a.random()));
        REQUIRE(a.isMember(a.random()));
        REQUIRE(a.isMember(a.random()));
    }

    SECTION("Method print()") {
        Set b;
        CHECK_THROWS(b.print());
    }
}
#endif