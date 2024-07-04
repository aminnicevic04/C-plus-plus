#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aktivnost {
protected:
    char id;
    string naziv;
    double budzet;
    int brojUcesnika;
    string sala;
public:
    Aktivnost(char id, string naziv, double budzet, int brojUcesnika, string sala)
        : id(id), naziv(naziv), budzet(budzet), brojUcesnika(brojUcesnika), sala(sala) {}

    virtual void prikaziInformacije() const = 0;
    virtual ~Aktivnost() {}
};

class SportskaAktivnost : public Aktivnost {
private:
    string sport;
public:
    SportskaAktivnost(char id, string naziv, double budzet, int brojUcesnika, string sala, string sport)
        : Aktivnost(id, naziv, budzet, brojUcesnika, sala), sport(sport) {}

    void prikaziInformacije() const override {
        cout << "ID: " << id << ", Naziv: " << naziv << ", Budzet: " << budzet
             << ", Broj Ucesnika: " << brojUcesnika << ", Sala: " << sala
             << ", Sport: " << sport << endl;
    }
};

class EdukativnaAktivnost : public Aktivnost {
private:
    string tema;
public:
    EdukativnaAktivnost(char id, string naziv, double budzet, int brojUcesnika, string sala, string tema)
        : Aktivnost(id, naziv, budzet, brojUcesnika, sala), tema(tema) {}

    void prikaziInformacije() const override {
        cout << "ID: " << id << ", Naziv: " << naziv << ", Budzet: " << budzet
             << ", Broj Ucesnika: " << brojUcesnika << ", Sala: " << sala
             << ", Tema: " << tema << endl;
    }
};

class UniverzitetskiCentar {
private:
    vector<Aktivnost*> aktivnosti;
public:
    void dodajAktivnost(Aktivnost* aktivnost) {
        aktivnosti.push_back(aktivnost);
    }

    void prikaziSveInformacije() const {
        for (const auto& aktivnost : aktivnosti) {
            aktivnost->prikaziInformacije();
        }
    }

    ~UniverzitetskiCentar() {
        for (auto& aktivnost : aktivnosti) {
            delete aktivnost;
        }
    }
};

int main() {
    SportskaAktivnost sport1('A', "Kosarka", 5000, 10, "Sala 1", "Kosarka");
    SportskaAktivnost sport2('B', "Fudbal", 7000, 22, "Stadion", "Fudbal");
    EdukativnaAktivnost edu1('C', "Matematika", 3000, 30, "Sala 2", "Linear Algebra");

    UniverzitetskiCentar centar;
    centar.dodajAktivnost(new SportskaAktivnost(sport1));
    centar.dodajAktivnost(new SportskaAktivnost(sport2));
    centar.dodajAktivnost(new EdukativnaAktivnost(edu1));

    cout << "Sve aktivnosti:" << endl;
    centar.prikaziSveInformacije();

    return 0;
}
