#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ekipa {
public:
    virtual int poeni() const = 0; // Virtuelna metoda za vraćanje broja poena
    virtual ~Ekipa() {} // Virtuelni destruktor
};

class Tim : public Ekipa {
private:
    string naziv;
    string drzava;
    int brojPoena;
public:
    Tim(string naziv, string drzava, int brojPoena = 0)
        : naziv(naziv), drzava(drzava), brojPoena(brojPoena) {}

    int poeni() const override {
        return brojPoena;
    }

    string getNaziv() const {
        return naziv;
    }

    string getDrzava() const {
        return drzava;
    }

    void dodajPoene(int poeni) {
        brojPoena += poeni;
    }

    // Preklapanje operatora =
    Tim& operator=(const Tim& other) {
        if (this == &other) {
            return *this;
        }
        naziv = other.naziv;
        drzava = other.drzava;
        brojPoena = other.brojPoena;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Tim& tim) {
        os << "Tim: " << tim.naziv << ", Drzava: " << tim.drzava << ", Poeni: " << tim.brojPoena;
        return os;
    }

    bool operator<(const Tim& other) const {
        return brojPoena < other.brojPoena;
    }

    bool operator==(const Tim& other) const {
        return naziv == other.naziv && drzava == other.drzava && brojPoena == other.brojPoena;
    }

    bool operator!=(const Tim& other) const {
        return !(*this == other);
    }

    bool operator>(const Tim& other) const {
        return brojPoena > other.brojPoena;
    }

    bool operator<=(const Tim& other) const {
        return !(*this > other);
    }

    bool operator>=(const Tim& other) const {
        return !(*this < other);
    }
};

class Turnir {
private:
    vector<Tim> timovi;
public:
    void dodajTim(const Tim& tim) {
        for (const auto& t : timovi) {
            if (t.getNaziv() == tim.getNaziv() && t.getDrzava() == tim.getDrzava()) {
                cout << "Tim vec postoji!" << endl;
                return;
            }
        }
        timovi.push_back(tim);
    }

    Tim getRekorder() const {
        Tim rekorder = timovi[0];
        for (const auto& tim : timovi) {
            if (tim.poeni() > rekorder.poeni()) {
                rekorder = tim;
            }
        }
        return rekorder;
    }

    void prikaziTimove() const {
        for (const auto& tim : timovi) {
            cout << tim << endl;
        }
    }
};

int main() {
    Tim tim1("Tim1", "Drzava1", 10);
    Tim tim2("Tim2", "Drzava2", 15);
    Tim tim3("Tim3", "Drzava3", 8);

    Turnir turnir;
    turnir.dodajTim(tim1);
    turnir.dodajTim(tim2);
    turnir.dodajTim(tim3);

    cout << "Turnir timovi:" << endl;
    turnir.prikaziTimove();

    Tim rekorder = turnir.getRekorder();
    cout << "Tim rekorder:" << endl;
    cout << rekorder << endl;

    return 0;
}