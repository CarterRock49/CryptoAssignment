// CryptoCurrencies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


/// An example class.
class CryptoManager{
private:
    //change this to change what file is opened
    const string fileDIR = "./TestData/Coins.csv";
    ifstream CryptoCSV;
    struct CryptoCurrencies{
        int rank;
        string name;
        string symbol;
        long long int marketcap;
    };

public:
    bool initialize(){
        //opens the file that the fileDIR varible has stored in it
        CryptoCSV.open(fileDIR);
        //opens file and checks to make sure it was successful
        if(CryptoCSV.is_open()){
                return true;
            } else {
                return false;
            }
    }

    int fileread(){


    }
};

/// Testing starts here. This takes the place of "main()" ///
TEST_CASE("<change this to something meaningful>"){
    // This is an example test of a class and a public function
    CryptoManager CM;
    CHECK(CM.initialize() == true);

}

/*
    while(!CryptoCSV.eof()){
        string entry;
        getline(CryptoCSV, entry, ',');
        cout << entry << endl;
    }
*/