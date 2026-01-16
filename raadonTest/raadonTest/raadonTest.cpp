
#include <iostream>
#include <ctime>

using namespace std;

class Apptab {
    int elements;
    int *tab;

public:
    Apptab(int e ):elements(e)  {
        this->tab = new int[e];
        for (int x = 0; x < elements; x++)
        {
            tab[x]= rand() % 1000;
        }

    }
    void wyswietlanie() {
        for (int x = 0; x < elements; x++)
        {
            cout << x << ": " << tab[x]<<endl;
        }

    }

    int Search() {
        int szukanaLiczba;
        bool znalezione = false;
        cout << "Podaj szukana liczbe: " << endl;
        cin >> szukanaLiczba;
        for (int x = 0; x < elements; x++)
        {
            if (szukanaLiczba == tab[x]) return x;
        }
        return -1;
    }

    void nieparzyste() {

        for (int x = 0; x < elements; x++)
        {
            if (tab[x] % 2 != 0) {
                cout << tab[x] << endl;
            }
        }
    }

    double srednia() {
        int suma = 0;
        for (int x = 0; x < elements; x++)
        {
            suma += tab[x];
        }
        return suma / elements;
    }

    int iloscnieparzystych() {
        int ilosc = 0;
        for (int x = 0; x < elements; x++)
        {
            if (tab[x] % 2 != 0) {
                ilosc++;
            }
        }
        return ilosc;

    }



};







int main()
{
    srand(time(NULL));
    int numer;
    cout << "Podaj number: ";
    cin >> numer;
    while (numer <= 20) {
        cout << "Podaj number: ";
        cin >> numer;

    }
    Apptab *obj =  new Apptab(numer);


    obj->wyswietlanie();
    cout << "znaleziono: " << obj->Search() << endl;
    obj->nieparzyste();
    cout<<"Srednia arytmetyczna wylosowanych liczb: " << obj->srednia() << endl;
    cout << "Ilosc liczb nieparzystych: " << obj->iloscnieparzystych() << endl;


    


    delete[] obj;
}
