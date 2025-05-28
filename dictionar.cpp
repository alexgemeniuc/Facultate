#include "Dictionar.h"

// Constructor - incarca datele la pornire
Dictionar::Dictionar() {
    incarcaDinFisier();
}

// Adauga un cuvant in dictionar si il salveaza
void Dictionar::adaugaCuvinte(const string& ro, const string& en) {
    cuvinte[ro] = en;
    cout << "Cuvant adaugat cu succes!" << endl;
    salveazaInFisier();  // Salvãm automat dupã adãugare
}

// Traducerea unui cuvant
// Traducerea unui cuvant
string Dictionar::traduceCuvinte(const string& ro) {
    auto it = cuvinte.find(ro);
    if (it != cuvinte.end()) {
        return it->second; // Returneaza traducerea corecta
    } else {
        return "Cuvantul nu a fost gasit in dictionar!";
    }
}

// Salveaza dictionarul in fisier
void Dictionar::salveazaInFisier() {
    ofstream fisier(numeFisier);
    if (!fisier) {
        cout << "Eroare la deschiderea fisierului pentru scriere!" << endl;
        return;
    }

    for (const auto& pereche : cuvinte) {
        fisier << pereche.first << "-" << pereche.second << endl;
    }

    fisier.close();
}

// Incarca datele din fisier
void Dictionar::incarcaDinFisier() {
    ifstream fisier(numeFisier);
    if (!fisier) {
        cout << "Nu s-a gasit fisierul, se va crea unul nou la salvare." << endl;
        return;
    }

    cuvinte.clear(); //Stregem dictionarul curent pentru a reincarca din fisier
    string linie, ro, en;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        if (getline(ss, ro, '-') && getline(ss, en)) {
            cuvinte[ro] = en;
        }
    }

    fisier.close();
}
