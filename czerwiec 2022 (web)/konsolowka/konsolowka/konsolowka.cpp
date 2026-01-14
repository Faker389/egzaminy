#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
class Osoba {
private:
    int id;
    string name;
public:
    static int classCounter;
    Osoba():id(0),name("") {
        this->classCounter +=1;
    };
    Osoba(string n,int id) :id(id), name(n) {
        this->classCounter += 1;
    };
    Osoba(const Osoba &person) {
        this->id = person.id;
        this->name = person.name;
        this->classCounter += 1;
    };
    void displayFields(string argument) {
        if (name.empty()) {
            cout << "Brak danych" << endl;
            return;
        }
        cout << "Czesc " << argument << ", mam na imie " << this->name << endl;
    }
};
int Osoba::classCounter = 0;

int main()
{
    Osoba* personObj1 = new Osoba();
    cout << "Liczba zarejestrowanych osob to " << Osoba::classCounter << endl;
    string name;
    int id;
    cout << "podaj id uzytkownika: "; cin >> id;
    cout << "podaj imie uzytkownika: "; cin >> name;
    Osoba* personObj2 = new Osoba(name, id);
    Osoba* personObj3 = new Osoba(*personObj2);
    personObj1->displayFields("Jan");
    personObj2->displayFields("Jan");
    personObj3->displayFields("Jan");
    cout << "Liczba zarejestrowanych osob to " << Osoba::classCounter << endl;
}
