// CryptoCurrencies.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


class CryptoManager{
private:
    ifstream CryptoCSV;
    //these are all strings because whenever I tried to make some of them ints I got tons of conversion errors 
    //so if say the requirements needed something like the marketcap as an int you would have to convert it later before use
    struct CryptoCurrencies{
        string rank;
        string name;
        string symbol;
        string marketcap;
    };

public:
    //member function takes in file name as a parameter, opens the file, and returns if it was successful
    bool initialize(string fileDIR){
        //opens the file that the fileDIR varible has stored in it
        CryptoCSV.open(fileDIR);
        //checks to make sure it was successful
        if(CryptoCSV.is_open()){
                return true;
            } else {
                return false;
            }
    }

    int fileread(){
        //I know the assignment calls for an array of structs but I decided to use a vector of structs since I learned it recently and wanted to try it out, I hope this is ok
        vector<CryptoCurrencies> fileinfo;
        string entry;
        int index = 0;
        //this first set is to get past the column names in the csv file
        //the getline statement takes the information up until in this case a ',' and inputs it in the variable 'entry'
        getline(CryptoCSV, entry, ',');
        getline(CryptoCSV, entry, ',');
        getline(CryptoCSV, entry, ',');
        // \n stands for newline
        getline(CryptoCSV, entry, '\n');
        //this is a while loop that continues until the end of the file each pass through it appends a struct to the vector(basically a dynmamic array)
        //it then adds each entry to the relevant variable for that struct
        while(!CryptoCSV.eof()){
            fileinfo.push_back(CryptoCurrencies());
            getline(CryptoCSV, entry, ','); 
            fileinfo[index].rank = entry;
            getline(CryptoCSV, entry, ',');
            fileinfo[index].name = entry;
            getline(CryptoCSV, entry, ',');
            fileinfo[index].symbol = entry;
            getline(CryptoCSV, entry, '\n');
            fileinfo[index].marketcap = entry;
            //interates on the variable 'index' to change the vector's row
            index++;
        }
        //returns the count of structs
        return fileinfo.size();
    }
};


// Testing starts here. This takes the place of "main()" //
TEST_CASE("Test the CryptoManager class and its member functions"){
    //const that holds what file is to be opened
    const string fileDIR = "Coins.csv";
    //const that holds that the intended stuct count for checking
    const int filelength = 50;


    CryptoManager CM;
    //checks if file is open
    CHECK(CM.initialize(fileDIR) == true);
    //checks if the count of structs is 50
    CHECK(CM.fileread() == filelength);

}

