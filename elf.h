#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "MosCraciun.h"

//clasa elfi primeste de la mosul lista de scrisori si analizeaza lista in functie de statutul fiecarui copil
//Dupa care dau mai departe lista de orase Mosului,lista cu cadouri trolilor,si numarul de acadele Doamnei Craciun

class elf :public MosCraciun
{
	vector<vector<string> > Lista;
	vector<vector<string> > inv;
	vector<vector<string> > lista_ref;
	vector<string> oras;
	vector<int> status = { 1,1,1,1,0,1 };
	int col_inv = 0;
	int lin_inv = 0;
	int col_Lista = 0;
	int lin_Lista = 0;
	int numar_acadele = 0;
	vector<string> spargere_cuv(string aux2);
public:

	elf();

	void afisare_input();
	void citire_inv(string);
	void afisare_inv();
	void set_up();
	vector<string> orase();
	int get_acadele();
	vector<vector<string> > get_Lista_ref();

	~elf();

	void functie();

private:
};