#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Address {

	string name_city;
	string name_street;
	int number_home;
	int number_apartment;
public:
	Address() {

	}
	Address(string new_city, string new_street, int new_home, int new_apartment) {
		name_city = new_city;
		name_street = new_street;
		number_home = new_home;
		number_apartment = new_apartment;
	}
	void get_output(ofstream &FFF) {
		
		FFF << name_city << " " << name_street << " " << number_home << " " << number_apartment << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	ifstream inFile("in.txt");
	int N;
	inFile >> N;
	
	string n_c = " ";
	string n_s = " ";
	int n_h = 0;
	int n_a = 0;
	Address* add = new Address[N];
	for (int i = 0; i < N; i++) {
		inFile >> n_c;
		inFile >> n_s;
		inFile >> n_h;
		inFile >> n_a;
		add[i] = Address(n_c, n_s, n_h, n_a);
	}
	ofstream OutFile("out.txt");
	OutFile << N << endl;

	for (int i = N-1; i >= 0; i--) {
		add[i].get_output(OutFile);
	}
	delete[] add;
	inFile.close();
	return 0;
}
