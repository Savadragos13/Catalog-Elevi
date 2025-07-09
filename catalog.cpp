#include <iostream>
using namespace std;

struct Elev {
    string nume;
    int clasa;
    float medie;
};

Elev e[100];
int nrElevi = 0;

void adaugaElev() {
    cout << "Numele elevului: ";
    cin >> e[nrElevi].nume;
    cout << "Clasa: ";
    cin >> e[nrElevi].clasa;
    cout << "Media: ";
    cin >> e[nrElevi].medie;
    nrElevi++;
    cout << "Elev adaugat cu succes!\n";
}

void afiseazaElevi() {
    if (nrElevi == 0) {
        cout << "Nu exista elevi inregistrati.\n";
        return;
    }
    for (int i = 0; i < nrElevi; i++) {
        cout << "- " << e[i].nume << ", clasa " << e[i].clasa << ", media " << e[i].medie << endl;
    }
}

void afiseazaRestantieri() {
    bool gasit = false;
    for (int i = 0; i < nrElevi; i++) {
        if (e[i].medie < 5) {
            cout << e[i].nume << " (" << e[i].medie << ") -- RESTANT\n";
            gasit = true;
        }
    }
    if (!gasit)
        cout << "Nu exista restantieri.\n";
}

void mediaPeClase() {
    int total[13] = {0};
    float suma[13] = {0};

    for (int i = 0; i < nrElevi; i++) {
        int cl = e[i].clasa;
        total[cl]++;
        suma[cl] += e[i].medie;
    }

    for (int i = 1; i <= 12; i++) {
        if (total[i] > 0) {
            cout << "Clasa " << i << ": media " << suma[i] / total[i] << endl;
        }
    }
}

void mediaTotala() {
    if (nrElevi == 0) {
        cout << "Nu exista elevi.\n";
        return;
    }

    float total = 0;
    for (int i = 0; i < nrElevi; i++) {
        total += e[i].medie;
    }
    cout << "Media totala a catalogului este: " << total / nrElevi << endl;
}

int main() {
    int optiune;
    do {
        cout << "\n=== Catalog Elevi ===\n";
        cout << "1. Adauga elev\n";
        cout << "2. Afiseaza toti elevii\n";
        cout << "3. Afiseaza restantierii\n";
        cout << "4. Media generala pe clasa\n";
        cout << "5. Media totala\n";
        cout << "6. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1: adaugaElev(); break;
            case 2: afiseazaElevi(); break;
            case 3: afiseazaRestantieri(); break;
            case 4: mediaPeClase(); break;
            case 5: mediaTotala(); break;
            case 6: cout << "La revedere!\n"; break;
            default: cout << "Optiune invalida!\n";
        }
    } while (optiune != 6);

    return 0;
}

