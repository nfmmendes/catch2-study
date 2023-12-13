#include <catch2/catch_test_macros.hpp>
#include <string>
using std::string;

class Simple
{
public:
    Simple(int a, string b) : integerValueA(a), stringValueB(b)
    {
    }

    int getA()
    {
        return integerValueA;
    }

    string getB()
    {
        return stringValueB;
    }

private:
    int integerValueA;
    string stringValueB;
};

TEST_CASE("Test with class object", "[starting]")
{
    Simple first(2, "first");
    Simple second(5, "second");

    REQUIRE(first.getA() == 2);
    REQUIRE(first.getB() == "first");
    REQUIRE(second.getA() == 5);
    REQUIRE(second.getB() == "second");
    REQUIRE_FALSE(first.getA() == second.getA());
    REQUIRE_FALSE(first.getB() == second.getB());
}