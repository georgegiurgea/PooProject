#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <climits>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include "MosCraciun.h"
#include "elf.h"
#include "trol.h"
#include "Doamna_Craciun.h"

using namespace std;

void set_oras(MosCraciun& obj1, elf& obj2);
void set_oras_doamna(MosCraciun& obj1, Doamna_Craciun& obj2);

int main()
{
	MosCraciun mos;
	mos.citire_csv("input.txt");

	elf Elf;
	Elf.set_up();
	Elf.afisare_input();

	Elf.citire_inv("inventar.txt");

	Elf.functie();
	Elf.orase();
	cout << Elf.get_acadele();
	trol Trol;
	cout << endl;
	Trol.set_list_Tr(Elf);
	Trol.pachet();

	set_oras(mos, Elf);
	cout << endl;
	mos.afisare_orase();

	Doamna_Craciun DCraciun;
	DCraciun.set_acadele_d(Elf);
	DCraciun.set_carbuni_d(Trol);

	DCraciun.Afisare_Buget_Extra();

	mos.calcul();

	set_oras_doamna(mos, DCraciun);

	DCraciun.afisare_orase_d();

	return 0;
}

void set_oras(MosCraciun& obj1, elf& obj2)
{
	obj1.set_ora(obj2.orase());
}

void set_oras_doamna(MosCraciun& obj1, Doamna_Craciun& obj2)
{
	obj2.set_orase(obj1.get_orase());
}