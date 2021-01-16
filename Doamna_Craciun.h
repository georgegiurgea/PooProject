#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "elf.h"
#include "trol.h"

class Doamna_Craciun
{
	vector<vector<string>> Lista_Doamna_Craciun;
	int numarAcadele = 0;
	int numarCarbuni = 0;
	vector<string> orase_d;
public:

	void set_acadele_d(elf object);
	void set_orase(vector<string>);
	void set_carbuni_d(trol obj);
	~Doamna_Craciun();
	int get_Carbuni();
	int get_Acadele();
	void afisare_orase_d();
	Doamna_Craciun()
	{
	}
	void Afisare_Buget_Extra();
};