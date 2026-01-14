#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::to_string;
using std::find;

/*
**********************************************
nazwa funkcji: generateNumbers
opis funkcji: Funkcja generuje liczby w zakresie od 1-49 i dodaje je do vectora
parametry: tab - pusty dwuwymiarowy vector o type liczb ca³kowitych
n - liczba ca³kowita okreœlaj¹ca d³ugoœæ vectora
zwracany typ i opis: brak
autor: Ja
***********************************************
*/
void generateNumbers(vector<vector<int>>& tab, int n) {
    for (int x = 0; x < n; x++) {
        vector<int> temp = {};
        while (temp.size() < 6) {
            int number = rand() % 49 + 1;
            if (!(find(temp.begin(), temp.end(), number) != temp.end())) temp.push_back(number);
        }
        tab[x] = temp;
    }
}
/*
**********************************************
nazwa funkcji: showNumbers
opis funkcji: Funkcja wyœwietla wszystkie liczby z dwuwymiarowego vectora liczb ca³kowitych
parametry: tab - dwuwymiarowy vector przechowywuj¹cy wylosowane wczeœniej liczby ca³kowite
n liczba ca³kowita okreœlaj¹ca d³ugoœæ vectora
zwracany typ i opis: brak
autor: Ja
***********************************************
*/
void showNumbers(const vector<vector<int>>& tab, int n) {
    for (int x = 0; x < n; x++) {
        string message = "Losowanie " + to_string(x + 1) + ": ";
        for (int y = 0; y < 6; y++) {
            message += to_string(tab[x][y]) + " ";
        }
        cout << message << endl;
    }
}
/*
**********************************************
nazwa funkcji: coundDuplicats
opis funkcji: Funkcja liczy wyst¹pienia poszczególnych liczb w dwuwymiaarowym vectorze liczb ca³kowitych
parametry: tab - dwuwymiarowy vector przechowywuj¹cy wylosowane wczeœniej liczby ca³kowite
n liczba ca³kowita okreœlaj¹ca d³ugoœæ vectora
zwracany typ i opis: brak
autor: Ja
***********************************************
*/
void coundDuplicats(const vector<vector<int>>& tab, int n) {
    int count;
    for (int searchingNumber = 1;searchingNumber <= 49;searchingNumber++) {
        count = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < 6; y++) {
                if (tab[x][y] == searchingNumber) count++;
            }
        }
        cout << "Wystapienia liczby " << searchingNumber << " : " << count << endl;
    }
}

int main() {
    int n = 0;

    while (n <= 0) {
        cout << "Ile wygenerowaæ losowañ?\n";
        cin >> n;
    }

    srand(time(NULL));

    vector<vector<int>> array(n, vector<int>(6, 0));
    generateNumbers(array, n);
    showNumbers(array, n);
    coundDuplicats(array, n);
    return 0;
}
