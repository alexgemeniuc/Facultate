#include "Aplicatie.h"
#include "TratareExceptii.h"

void Aplicatie::ruleaza() {
    string optiune;
    string cuvant, traducere;

    while (true) {
        cout << "\n1. Introducere cuvant" << endl;
        cout << "2. Traducere cuvant" << endl;
        cout << "0. Iesire" << endl;

        try {
            optiune = TratareExceptii::citesteOptiune(); // Acum este string

            if (optiune == "1") {
                cin.ignore();

                cout << "Introduceti cuvantul in romana: ";
                cuvant = TratareExceptii::citesteCuvant();

                cout << "Introduceti traducerea in engleza: ";
                traducere = TratareExceptii::citesteCuvant();

                dictionar.adaugaCuvinte(cuvant, traducere);

            } else if (optiune == "2") {
                cin.ignore();

                cout << "Introduceti cuvantul de tradus: ";
                cuvant = TratareExceptii::citesteCuvant();

                traducere = dictionar.traduceCuvinte(cuvant);

                if (traducere == "Cuvantul nu a fost gasit in dictionar!") {
                    cout << traducere << endl;
                    cout << "Introduceti traducerea pentru \"" << cuvant << "\": ";
                    traducere = TratareExceptii::citesteCuvant();
                    dictionar.adaugaCuvinte(cuvant, traducere);
                } else {
                    cout << "Traducerea este: " << traducere << endl;
                }

            } else if (optiune == "0") {
                return;

            } else {
                cout << "Optiune indisponibila! Incercati din nou." << endl;
            }

        } catch (const exception& e) {
            cout << "Eroare neasteptata: " << e.what() << ". Incercati din nou." << endl;
        }
    }
}
