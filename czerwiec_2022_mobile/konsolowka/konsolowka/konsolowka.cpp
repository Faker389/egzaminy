
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

/********************************************************
* nazwa funkcji: fillTable
* parametry wejœciowe: tab - pusta tablica liczb ca³kowitych, size - rozmiar tablicy
* wartoœæ zwracana: brak
* autor: JA
* ****************************************************/
void fillTable(int *tab,int size) {
    for (int x = 0;x < size;x++) {
        tab[x] = rand() % 100 + 1;
    }
}
/********************************************************
* nazwa funkcji: findIndexOf
* parametry wejœciowe: tab - tablica liczb ca³kowitych, size - rozmiar tablicy searchNumber - liczba której index chcemy znaleŸæ w tablicy
* wartoœæ zwracana: liczba ca³kowita w postaci indexu poszukiwanej liczby w tablicy
* autor: JA
* ****************************************************/
int findIndexOf(int* tab, int size, int searchNumber) {
    for (int x = 0;x < size;x++) {
        if (tab[x] == searchNumber) return x;
    }
    return -1;
}
/********************************************************
* nazwa funkcji: showArray
* parametry wejœciowe: tab - pusta tablica liczb ca³kowitych, size - rozmiar tablicy
* wartoœæ zwracana: brak
* autor: JA
* ****************************************************/
void showArray(int* tab, int size) {
    cout << "Tablica liczb: ";
    for (int x = 0;x < size;x++) {
        cout << tab[x] << ",";
    }
    cout << endl;
}
int main()
{
    int len=0;
    while (len < 50) {
        cout << "Podaj dlugosc tablicy (minimum 50): ";cin >> len;
    }
    int* tab = new int[len];
    srand(time(NULL));
    fillTable(tab,len);
    int searchNumber = 0;
    while (searchNumber < 1||searchNumber>100) {
        cout << "Podaj szukana liczbe z przedzialu <1,100>: ";cin >> searchNumber;
    }
    showArray(tab, len);
    int result = findIndexOf(tab, len, searchNumber);
    if ( result!= -1) {
        cout << "Znaleziono liczbe: " << searchNumber << " na indexie: " << result;
    }
    else {
        cout << "Tablica nie zawiera poszukiwanej liczby";
    }
    delete[] tab;
    return 0;
}
