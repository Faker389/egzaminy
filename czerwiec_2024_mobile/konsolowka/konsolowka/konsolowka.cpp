#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
/*
************************************************
 nazwa: calculatePoints
 opis: Funkcja liczy punkty z wylosowanych kostek na podstawie algorytmu
 parametry: tab - jest to vector liczb ca³kowitych przechowywuj¹cy wyniki rzuconych kostek
 n - d³ugoœæ vectora
 zwracany typ i opis: zwracana jest liczba ca³kowita z wynikiem uzyskanych punktów
 autor: Ja
************************************************
*/
int calculatePoints(vector<int>& tab, int n) {
	int points = 0;
	for (int number = 1; number <= 6;number++) {
		int count = 0;
		for (int x = 0;x < n;x++) {
			if (tab[x] == number) count++;
		}
		if (count >= 2) {
			points += number * count;
		}
	}
	return points;
}
/*
************************************************
 nazwa: populateTab
 opis: Funkcja losuje rzuty kostk¹ i zapisuje je do vectora
 parametry: tab - jest to vector liczb ca³kowitych do przechowywania wyników rzuconych kostek
 n - d³ugoœæ vectora
 zwracany typ i opis: brak
 autor: Ja
************************************************

*/
void populateTab(vector<int> &tab, int n) {
	for (int x = 0;x < n;x++) {
		int cubeThrow = rand() % 6 + 1;
		cout << "Kostka " << x + 1 << " : " << cubeThrow << endl;
		tab[x]=(cubeThrow);
	}
	cout << "Liczba uzyskanych punktow:  " << calculatePoints(tab,n) << endl;
}
int main()
{
	char gameState = 't';
	while (gameState == 't') {
		int throwCount = 0;
		while (throwCount<3||throwCount>10)
		{
			cout << "Ile kostek chcesz rzuciæ? (3-10)" << endl;
			cin >> throwCount;
		}
		vector<int> array(throwCount);
		populateTab(array, throwCount);
		cout << "Jeszcze raz? (t/n)" << endl;
		cin >> gameState;
	}
}
