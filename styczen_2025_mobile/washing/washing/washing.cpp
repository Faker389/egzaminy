#include <iostream>
using std::string;
using std::endl;
using std::cout;
using std::cin;
class AGD {
public:
	/* ***********************************************
		nazwa :showComunicat
		opis : wyœwietla przekazany w parametrze argument
		parametry : argument - text do wyswietlenia w consoli
		zwracany typ i opis : brak
		autor : JA
		************************************************/
	void showComunicat(string argument) {
		cout << argument << endl;
	}
};

class WashingMachine : AGD {
private:
	int washingProgram = 0;
public:
	/* ***********************************************
	nazwa :setWaschingProgram
	opis : Ustawia program prania na liczbe od 1-12 lub 0 jesli liczba przekracza ten przedzial
	parametry : program - liczba ca³kowita jako numer programu
	zwracany typ i opis : zwracany typ int, zwraca ustawiony przez metode program prania
	autor : JA
	************************************************/
	int setWaschingProgram(int program) {
		if (program >= 1 && program <= 12) {
			this->washingProgram = program;
			this->showComunicat("Program zosta³ ustawiony");
		}
		else {
			this->washingProgram = 0;
			this->showComunicat("Podany niepoprawny numer programu");
		}
		return this->washingProgram;
	}
};
class VacuumCleaner : AGD {
private:
	bool isVacuumCleanerOn = false;
public:
	/* ***********************************************
	nazwa :on
	opis : Je¿eli odkurzacz jest wylaczony , wlacza go i pokazuje komunikat
	parametry : program - brak
	zwracany typ i opis : brak
	autor : JA
	************************************************/
	void on() {
		if (this->isVacuumCleanerOn)return;
		this->isVacuumCleanerOn = true;
		this->showComunicat("Odkurzacz w³¹czono");
	}
	/* ***********************************************
	nazwa :off
	opis : Je¿eli odkurzacz jest wlaczony , wylacza go i pokazuje komunikat
	parametry : program - brak
	zwracany typ i opis : brak
	autor : JA
	************************************************/
	void off() {
		if (!this->isVacuumCleanerOn)return;
		this->isVacuumCleanerOn = false;
		this->showComunicat("Odkurzacz wy³¹czono");
	}
};
int main()
{
	AGD *klasaBazowa = new AGD();
	WashingMachine* pralka = new WashingMachine();
	VacuumCleaner* odkurzacz = new VacuumCleaner();
	int WashingProgram;
	cout << "Podaj numer prania 1-12: ";cin >> WashingProgram;
	pralka->setWaschingProgram(WashingProgram);
	odkurzacz->on();
	klasaBazowa->showComunicat("Odkurzacz wy³adowa³ siê");
	odkurzacz->off();

	delete klasaBazowa;
	delete odkurzacz;
	delete pralka;
}
