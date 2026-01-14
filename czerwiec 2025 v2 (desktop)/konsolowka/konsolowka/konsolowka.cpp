#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;
class Hashing {
private:
	string text;
	int key;
public:
	Hashing(string t, int k) :text(t), key(k) {};
	string optionalData(string t, int k) {
		if(!t.empty()){
			this->text = t;
			this->key = k;
		}
		return cesarHashing();
	}
	string cesarHashing() {
		if (key == 0) {
			return text;
		}
		string hashedText = "";
		for (int x = 0;x < this->text.size();x++) {
			int currentAsciiVal = int((char)text[x]);
			if ((currentAsciiVal < 97 || currentAsciiVal>122)&&currentAsciiVal!=32) {
				cout << "Text can only contain lower letters" << endl;
				return "";
			}
			char movedChar=32;
			if (currentAsciiVal != 32) {
				if (key > 0) {
					if (currentAsciiVal + key > 122) movedChar = char(((currentAsciiVal + key) - 123) + 97);
					else movedChar =char(currentAsciiVal + key);
				}else{ 
					if (currentAsciiVal + key < 97) movedChar = char(((currentAsciiVal + key) - 97) + 122);
					else movedChar = char(currentAsciiVal + key);
				}
			}
			hashedText += movedChar;
		}
		return hashedText;
	}

};
int main()
{
	string txt="cos tam";
	int key=3; 
	//cout << "Provide a text for hashing: ";getline(cin,txt);
	//cout << "Provide a key for hashing: ";cin >> key;
	Hashing  *hashObject = new Hashing(txt, key);
	hashObject->cesarHashing();
	cout << hashObject->optionalData("abc", key) << endl;
	cout << hashObject->optionalData("xyz", key) << endl;
	cout << hashObject->optionalData("def", -3) << endl;
	cout << hashObject->optionalData("abc", 29) << endl;
	cout << hashObject->optionalData("ab cd", 2)<<endl;
}

