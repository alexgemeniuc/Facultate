#ifndef DICTIONAR_H
#define DICTIONAR_H

#include <iostream>
#include <map>
#include <fstream> // Pentru citirea/scrierea fisierelor
#include <sstream> //Pentru manipularea string-urilor

using namespace std;

class Dictionar {
private:
    map<string, string> cuvinte;
    const string numeFisier = "dictionar.txt"; //Numele fisierului

public:
    Dictionar(); //Constructor implicit adaugat
    void adaugaCuvinte(const string& ro, const string& en);
    string traduceCuvinte(const string& ro);
    void salveazaInFisier(); //Salveaza cuvintele in fisier
    void incarcaDinFisier(); //Incarca cuvintele din fisier
};

#endif
