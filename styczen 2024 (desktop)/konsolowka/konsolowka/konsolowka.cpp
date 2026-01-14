#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::to_string;
using std::endl;
using std::cin;
/*
**********************************************
nazwa funkcji: checkGender
opis funkcji: Sprawdza jakiej p³ci jest posiadacz peselu na podstawie 10 znaku w peselu
parametry: pesel typu string przechowuje wpisany przez u¿ytkownika pesel
zwracany typ i opis: zwracany jest znak bed¹cy K w przypadku gdy 10 liczba w peselu jest parzysty i M gdy liczba jest nieparzysta
autor: JA
***********************************************
*/
char checkGender(string pesel) {
	try
	{
		int genderNumber = (int)pesel[9]-'0';
		if (genderNumber % 2 == 0||genderNumber==0) return'K';
		else return 'M';
	}
	catch (const std::exception&)
	{
		cout << "Invalid pesel format"<<endl;
	}
}
/*
**********************************************
nazwa funkcji: checkControlSum
opis funkcji: Sprawdza sume kontroln¹ peselu na podstawie algorytmu
parametry: pesel typu string przechowuje wpisany przez u¿ytkownika pesel
zwracany typ i opis: zwracana jest wartosc logiczna True w zale¿noœci czy suma jest poprawna False w przeciwnym razie
autor: JA
***********************************************
*/
bool checkControlSum(string pesel) {
	int controlNumber = (int)pesel[10] - '0';
	int S = 0;
	int numberWeights[10] = { 1,3,7,9,1,3,7,9,1,3 };
	for (int x = 0;x < 10;x++) {
		S += ((int)pesel[x] - '0') * numberWeights[x];
	}
	int M = S % 10;
	int R;
	if (M == 0) R = 0;
	else R = 10 - M;
	return R == controlNumber;
	
}
int main()
{

	string pesel="";
	while (pesel.size() !=11) {
		cout << "Podaj numer pesel (ciag 11 liczb): ";cin >> pesel;
	}
	cout << "plec : " << checkGender(pesel) << " suma kontrolna: " << checkControlSum(pesel) << endl;
}