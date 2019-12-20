#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct TSamochod {
	string marka;
	string model;
	int rocznik;
};

void wypisz_samochody(const TSamochod *stab, int N)
{
	string kreska(34, '-');
	cout << kreska << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << setw(10) << stab[i].marka << " | " << setw(10) << stab[i].model << " | " << setw(5) << stab[i].rocznik << " |" << endl;
	}
	cout << kreska << endl << endl;
}

TSamochod* fnajstarszy(TSamochod *samochody, int ilosc)
{
	//...
	//...
	return samochody;
}

int main()
{
	TSamochod komis[10] = { { "opel", "zafira", 2010 }, { "ford", "focus", 2012 }, { "toyota","avensis",2005 }, {"fiat","panda",2008} };
	int ilosc_samochodow = 4;
	TSamochod* stary = fnajstarszy(komis, ilosc_samochodow);
	wypisz_samochody(komis, ilosc_samochodow);
	cout << "Najstarszy samochod to:"<< endl;
	wypisz_samochody(stary, 1);
	system("date");
	return 1;
}
