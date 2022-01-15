// CryptoCurrencies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/// An example function.
string SomeFunc(string s)
{
    return "Hello " + s;
}

/// An example class.
class SomeClass
{
public:
    bool SomeMemberFunc(bool b)
    {
        // Return the NOT of b
        return !b;
    }
};

/// Testing starts here. This takes the place of "main()" ///
TEST_CASE("<change this to something meaningful>")
{
    // This is an example test of function
    CHECK(SomeFunc("world") == "Hello world");

    // This is an example test of a class and a public function
    SomeClass sc;
    CHECK(sc.SomeMemberFunc(true) == false);
}