#ifndef TRATAREERORI_H
#define TRATAREERORI_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class TratareExceptii {
public:
    static bool esteCuvantValid(const string& cuvant);
    static string citesteOptiune();  // Acum returneazã string, NU int
    static string citesteCuvant();
};

#endif
