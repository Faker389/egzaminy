#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
/* ***********************************************
klasa: Klasa
opis : Klasa liczy wystapienie samog³osek w wyrazach jak i usuwa powtórzenia liter i znaków w wyrazach
metody : countVowels zwraca iloœæ wyst¹pieñ samog³osek w podanym w prametrze wyrazie
eraseDuplicats - usuwa powtarzaj¹ce sie obok siebie litery i znaki w wyrazie i zwraca wynik
autor : JA
************************************************/
class Klasa {
public:
    static string vowels ;
    static int countVowels(string text) {
        if (text == "") return 0;
        int vowelsCount = 0;
        for (int x = 0;x < text.size();x++) {
            if (vowels.find(text[x]) != string::npos)vowelsCount++;
        }
        return vowelsCount;
    }
    static string eraseDuplicats(string text) {
        char previousLetter = text[0];
        string erasedText = "";
        erasedText+= previousLetter;
        for (int x = 1;x < text.size();x++) {
            if (text[x] != previousLetter) {
                erasedText += text[x];
                previousLetter = text[x];
            }
        }
        return erasedText;
    }
};
string Klasa::vowels="a¹eêiouóyA¥EÊIOUÓY";
int main()
{
    Klasa* objekt = new Klasa();
    cout << objekt->countVowels("a¹¹¹aa cos tam yy i nic") << endl;
    cout << objekt->eraseDuplicats("aacos    tammmmduz   oooopowtorzen") << endl;
    delete objekt;
}
