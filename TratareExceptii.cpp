#include "TratareExceptii.h"
#include <cctype>


bool TratareExceptii::esteCuvantValid(const string& cuvant) {
    for (char c : cuvant) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Citirea unei opțiuni valide (doar cifre), returnează STRING
string TratareExceptii::citesteOptiune() {
    string input;

    while (true) {
        try {
            cout << "Introduceti optiunea: ";
            cin >> input;

            for (char c : input) {
                if (!isdigit(c)) {
                    throw invalid_argument("Eroare! Introduceti doar cifre.");
                }
            }

            return input; // Returnăm string, evităm conversia în int

        } catch (const invalid_argument& e) {
            cout << e.what() << " Incercati din nou." << endl;
            cin.clear();
        }
    }
}

// Citirea unui cuvânt valid (doar litere)
string TratareExceptii::citesteCuvant() {
    string input;

    while (true) {
        try {
            cin >> ws; // Elimină spațiile albe rămase
            getline(cin, input);

            if (!esteCuvantValid(input)) {
                throw invalid_argument("Eroare! Introduceti doar litere.");
            }

            return input;

        } catch (const invalid_argument& e) {
            cout << e.what() << " Incercati din nou." << endl;
        }
    }
}
