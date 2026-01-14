
#include <iostream>
using std::cout;
using std::endl;
using std::string;
/*
******************************************************
 nazwa klasy: Film
 pola: title - tytu³ danego filmu
 borrowNumber - liczbe wypo¿yczeñ danego filmu
 metody: getTitle - zwraca strina w postaci tytu³u filmu
 setTitle - brak zwracanych danych sprawdza czy dlugosc tytulu nie jest wieksza niz 20 i ustawia go jako pole klasy
 getBorrowNumber - zwraca ilosc po¿yczonych filmów w postaci liczby ca³kowitej
 incrementBorrowNumber - zwieksza liczbe pozyczeñ filmu o 1
 informacje: 
 autor: JA
*****************************************************
*/
class Film {
protected:
    string title;
    int borrowNumber;
public:
    Film() :title(""), borrowNumber(0) {};
    void setTitle(string title) {
        if (title.size() > 20) {
            cout << "Maksymalna d³ugoœæ tytu³u to 20 znaków" << endl;
            return;
        }
        this->title = title;
    }
    string getTitle() {
        return this->title;
    }
    int getBorrowNumber() {
        return this->borrowNumber;
    }
    void incrementBorrowNumber() {
        this->borrowNumber += 1;
    }
};
int main()
{
    Film *FilmObject =new Film();
    FilmObject->setTitle("Przykladowy tytul");
    cout << FilmObject->getTitle()<<endl;
    cout <<"wartosc przed inkrementacja: "<< FilmObject->getBorrowNumber() << endl;
    FilmObject->incrementBorrowNumber();
    cout << "wartosc przed inkrementacja: " << FilmObject->getBorrowNumber() << endl;
}

