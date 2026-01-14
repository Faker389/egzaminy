#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
/*
*******************************************************
 nazwa funkcji: removeNumber
 parametry wejœciowe: array - vector liczb ca³kowitych z przedzia³u 2-100 , number - liczba calkowita
 wartoœæ zwracana: brak
 informacje: funkcja wyszukuje w vectorze podan¹ liczbe i jej wielokrotnoœci i je usuwa
 autor: JA
****************************************************
*/
void removeNumber(vector<int>& array, int number) {
	vector<int> temp;
	for (int x = 0;x < array.size();x++) {
		if (array.at(x) == number ||array.at(x) % number != 0) temp.push_back(array.at(x));
	}
	array = temp;
}
/*
*******************************************************
 nazwa funkcji: showPrimeNumbers
 parametry wejœciowe: array - vector liczb ca³kowitych z przedzia³u 2-100
 wartoœæ zwracana: brak
 informacje: funkcja wyœwietla liczby z vecotra
 autor: JA
****************************************************
*/
void showPrimeNumbers(vector<int>& array) {
	cout << "Liczby pierwsze z przedzialu <2-100>: ";
	for (int x = 0;x < array.size();x++) {
		cout << array.at(x) <<",";
	}
}
/*
*******************************************************
 nazwa funkcji: fillUpTable
 parametry wejœciowe: array - pusty vector liczb ca³kowitych
 wartoœæ zwracana: brak
 informacje:wype³nia vector wartoœciami z przedzia³u <2,100>
 autor: JA
****************************************************
*/
void fillUpTable(vector<int>& array) {
	for (int x = 2;x <=100;x++) {
		array.push_back(x);
	}
}
int main()
{
	int len = 100;
	vector<int> array;
	fillUpTable(array);
	vector<int> numbersToRemove = { 2,3,5,7 };
	removeNumber(array, 2);
	for (int x = 0;x < numbersToRemove.size();x++) {
		removeNumber(array, numbersToRemove.at(x));
	}
	showPrimeNumbers(array);
}
