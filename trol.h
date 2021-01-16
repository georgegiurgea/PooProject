#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "elf.h"

//clasa troli care primimesc de la de la elfi lista de cadouri si le impacheteaza in fucntie de copil
//dupa care da  doamnei Craciun numarul carbunilor folositi
class trol
{
	vector<vector<string>> lista_trol;
	int roz = 0, blue = 0, carbune = 0;
public:

	void set_list_Tr(elf& obj);
	void afisare_lista();
	int get_carbune();
	void pachet();
	trol();
	~trol();
};