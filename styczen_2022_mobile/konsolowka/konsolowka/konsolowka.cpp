
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

class SortClass {
public:
	static const int len = 10;
	int tab[len];
	SortClass() {
		for (int x = 0;x < this->len;x++) {
			tab[x] = rand() % 100;
		}
	}
	/********************************************************
	* nazwa funkcji: sort
	* parametry wejœciowe: brak
	* wartoœæ zwracana: brak
	* autor: Ja
	* ****************************************************/

	void sort() {
		int minimalIndex;
		for (int i = 0;i < this->len;i++)
		{
			minimalIndex = i;
			for (int j = i + 1;j < this->len;j++) {
				if (this->tab[j] < this->tab[minimalIndex]) minimalIndex = j;
			}

			int temp = this->tab[i];
			this->tab[i] = this->tab[minimalIndex];
			this->tab[minimalIndex] = temp;
		}
		cout << "Maksymalna wartosc z tablicy to: " << findMaxVal();
	}
private:
	/********************************************************
	* nazwa funkcji: findMaxVal
	* parametry wejœciowe: brak
	* wartoœæ zwracana: najwiêksza liczba z posortowanej tabeli liczb ca³kowitych
	* autor: Ja
	* ****************************************************/
	int findMaxVal() {
		int maxVal = 0;
		for (int x = 0;x < this->len;x++) {
			if (this->tab[x] > maxVal) maxVal = this->tab[x];
		}
		return maxVal;
	}
};
int main()
{
	srand(time(NULL));
	SortClass *klasa = new SortClass();
	klasa->sort();
	return 0;
}
