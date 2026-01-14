
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
/*
**********************************************
nazwa funkcji: NWD
opis funkcji: Liczy Najwiêksz¹ Wspóln¹ Wielokrotnoœæ
parametry: a i b - liczby ca³kowite sa to 2 liczby podane przez u¿ytkownika
zwracany typ i opis: zwraca liczbe ca³kowit¹ w postaci obliczonej nawiêkszej wspólnej wielokrotnoœci
autor: JA
***********************************************
*/
int NWD(int a, int b) {
	while (a != b) {
		if (a > b)a -= b; 
		else b -= a; 
	}
	return a;

}
int main()
{
	int a=-1, b=-1;
	while (a <= 0) {
		cout << "Prosze wpisac liczbe a: ";cin >> a;
	}
	while (b<=0)
	{
		cout << "Prosze wpisac liczbe b: ";cin >> b;
	}
	cout << "Wynikiem NWD dla liczb : " << a << " i " << b << " jest liczba " << NWD(a, b) << endl;
	return 0;
}
