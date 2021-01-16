#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#define V 6

using namespace std;

//primeste de la copii scrisorile si le da elfilor,dupa primeste lista cu orasele unde trebuie sa mearga
//si calculeaza drumul critic, dupa care il imparte cu Doamna craciun

class MosCraciun
{
	vector<vector<string> > date;
	vector<string> v;
	vector<string> orase;
	vector<string>drum;
	int lines_input = 0;
	int col_input = 0;
	int minfunc(int key[], bool mstSet[]);
	void afisare_graf(int parinte[], int graf[V][V]);
	void primalg(int graf[V][V]);
public:

	MosCraciun();
	~MosCraciun();
	void set_ora(vector<string>);
	void citire_csv(string nume);

	void afisare_csv(vector<vector<string> >, int, int);
	vector<vector<string> > get_date();
	int get_col_input();
	int get_lines_input();
	vector<string > get_orase();
	void afisare_orase();
	void calcul();
};