#include <iostream>
#include <ctime>

using namespace std;

int rzuty(int wynik)
{
	do {
		wynik = rand() % 11;
	} while (wynik == 0);
	return wynik;
}

int symulacjaTestow(int iloscKosci, int ST, bool poprawne, int& pktS, int iloscKosciStala, int STStaly)//testowe rzuty
{
	int pkt = 0;
	int wynikRzutu = 0;
	int wynikRzutuStale = 0;
	int rzut = 0;
	if (!poprawne)
	{
		return 0;
	}
	for (int i = 1; i <= iloscKosciStala; i++)
	{
		wynikRzutuStale = rzuty(rzut);
		cerr << "\nRzut " << i << " kością dla wartości stałych jest równy " << wynikRzutuStale << endl;
		if (wynikRzutuStale >= ST)
		{
			pktS++;
		}
		if (wynikRzutuStale == 1)
		{
			pktS--;
		}
	}
	for (int i = 1; i <= iloscKosci; i++)	//test z wykorzystaniem danych uzyskanych od użytkownika
	{
		wynikRzutu = rzuty(rzut);
		cerr << "\nRzut " << i << " kością jest równy " << wynikRzutu << endl;
		if (wynikRzutu >= ST)
		{
			pkt++;
		}
		if (wynikRzutu == 1)
		{
			pkt--;
		}
	}
	return pkt;
}

int main()
{
	setlocale(LC_ALL, "");

	int iloscKosci;
	int ST;
	bool poprawne = true;
	int punkty;
	int punktyStale = 0;
	int iloscKosciStala = 5;
	int STStaly = 5;
	srand(time(0));

	cout << "Podaj ilość kości do rzutu: "; cin >> iloscKosci;
	cout << "Podaj stopień trudności: "; cin >> ST;
	cout << "\nStałe wartości testów to:\nLiczba kości: " << iloscKosciStala << "\nStopień trudności: " << STStaly << endl;
	if (iloscKosci <= 0 || ST <= 0 || ST > 10)
	{
		poprawne = false;
	}

	punkty = symulacjaTestow(iloscKosci, ST, poprawne, punktyStale, iloscKosciStala, STStaly);

	cout << "\nLiczba sukcesów jaką otrzymał gracz dla wartości stałych wynosi: " << punktyStale << endl;
	cout << "\nLiczba sukcesów jaką otrzymał gracz wynosi: " << punkty << endl;
}