#include <iostream>
using std::string;
using std::cout;
using std::endl;
/* ************************************************
 klasa: Notatka
 opis: Klasa jest pojedyñcz¹ instancja notatki 
 pola: notesCount - przechowuje liczbe instancji klasy
 id - przechowuje id danej notatki
 noteTitle - przechowuje tytu³ notatki
 noteDescription - przechowuje opis notatki
 autor: <numer zdaj¹cego>
*************************************************/
class Notatka {
private:
    static int notesCount;
    int id;
protected:
    string noteTitle;
    string noteDescription;
public:
    Notatka(string title, string description):noteTitle(title),noteDescription(description) {
        this->notesCount += 1;
        this->id = this->notesCount;
    }
    void showNoteDetails() {
        cout << "Title :" << this->noteTitle << " description: " << this->noteDescription << endl;
    }
    void showAllFields() {
        cout <<"ID: "<<this->id << "Title :" << this->noteTitle << " description: " << this->noteDescription << " notes conuter: " << this->notesCount << endl;
    }
};
int Notatka::notesCount = 0;
int main()
{
    Notatka* note1 = new Notatka("Zrobic zakupy", "jak najszybciej");
    note1->showNoteDetails();
    note1->showAllFields();
    Notatka* note2 = new Notatka("Druga notatka", "z drugim opisem");
    note2->showNoteDetails();
    note2->showAllFields();
}
