#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
class FilterPrimeNumbers {
public:
	vector<int> array;
	FilterPrimeNumbers() {
		for (int x = 2;x <= 100;x++) {
			this->array.push_back(x);
		}
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
	void showPrimeNumbers() {
		cout << "Liczby pierwsze z przedzialu <2-100>: ";
		for (int x = 0;x < array.size();x++) {
			cout << array.at(x) << ",";
		}
	}
	/*
*******************************************************
 nazwa funkcji: removeNumber
 parametry wejœciowe: array - vector liczb ca³kowitych z przedzia³u 2-100 , number - liczba calkowita
 wartoœæ zwracana: brak
 informacje: funkcja wyszukuje w vectorze podan¹ liczbe i jej wielokrotnoœci i je usuwa
 autor: JA
****************************************************
*/
	void removeNumber(int number) {
		vector<int> temp;
		for (int x = 0;x < array.size();x++) {
			if (array.at(x) == number || array.at(x) % number != 0) temp.push_back(array.at(x));
		}
		array = temp;
	}
};
int main()
{
	FilterPrimeNumbers* object = new FilterPrimeNumbers();
	vector<int> numbersToRemove = { 2,3,5,7 };
	for (int x = 0;x < numbersToRemove.size();x++) {
		object->removeNumber(numbersToRemove.at(x));
	}
	object->showPrimeNumbers();
}
