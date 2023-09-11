#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class planet {

public:

	planet() {

	}


private:
	string name;
	string date;
	double radius;




	friend ostream& operator<< (ostream& os, planet& planet)
	{

		os << "Название: " << planet.name << "\tДата: " << planet.date << "\tРадиус: " << planet.radius;
		return os;
	}

	friend istream& operator>> (istream& is, planet& planet)
	{

		is >> planet.name >> planet.date >> planet.radius;
		planet.name = planet.name.substr(1, planet.name.size() - 2);
		return is;
	}
};




int main() {
	setlocale(LC_ALL, "Ru");
	string path = "test.txt";
	ifstream fs;
	fs.open(path, fstream::out);
	if (!fs.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		while (true)
		{
			planet s;
			fs >> s;
			cout << s << endl;
			if (fs.eof()) {
				break;
			}



		}
	}

	return 0;
}