#include "MosCraciun.h"

void MosCraciun::calcul()
{
	int graf[V][V] = { {0	,4793	,0	,0	,0	,4880},
						{4793	,0	,162	,0	,350	,0},
						{0	,162	,0	,468	,340	,0},
						{0	,0	,468	,0	,690	,330},
						{0	,350	,340	,690	,0	,795},
						{4880	,0	,0	,330	,795	,0} };

	primalg(graf);
}

MosCraciun::MosCraciun()
{
	citire_csv("input.txt");
}

MosCraciun::~MosCraciun()
{
	this->v.clear();
	this->orase.clear();
	this->date.clear();
	//cout << "mos craciun distrus" << endl;
}

void MosCraciun::set_ora(vector<string> orase)
{
	this->orase = orase;
}

vector<vector<string> > MosCraciun::get_date()
{
	return this->date;
}
int MosCraciun::get_col_input()
{
	return this->col_input;
}
int MosCraciun::get_lines_input()
{
	return this->lines_input;
}
vector <string> MosCraciun::get_orase()
{
	return this->drum;
}
void MosCraciun::afisare_orase()
{
	this->orase.push_back("Laponia");
	sort(this->orase.begin(), this->orase.end());
	this->orase.erase(unique(this->orase.begin(), this->orase.end()), this->orase.end());
	cout << endl;
	cout << "Orasele din Arabia Saudita sunt " << endl;
	for (size_t i = 0;i < this->orase.size();i++)
	{
		cout << this->orase.at(i) << " ";
	}
}
void MosCraciun::afisare_csv(vector<vector<string> > da, int lin, int col)
{
	for (size_t i = 0;i < lin;i++)
	{
		for (size_t j = 0;j < col;j++)
			cout << da[i][j] << " ";
		cout << endl;
	}
}

void MosCraciun::citire_csv(string nume)
{
	this->date.clear();
	this->v.clear();
	this->col_input = 0;

	try {
		ifstream in;

		string line, field;

		in.open(nume);
		if (!in)throw 1;
		this->lines_input = 0;

		while (getline(in, line))
		{
			this->col_input = v.size();
			this->v.clear();

			stringstream ss(line);
			++this->lines_input;
			while (getline(ss, field, ','))
			{
				this->v.push_back(field);
			}
			this->date.push_back(this->v);
		}

		in.close();
	}
	catch (int x) {
		cout << "eroare deschidere fisier\MosCraciun" << endl;
	}
}

int MosCraciun::minfunc(int key[], bool vizitat[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (vizitat[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void MosCraciun::afisare_graf(int parinte[], int graf[V][V])
{
	vector<int> intVec = { 1,5,3,0,2,4 };
	string y;
	int cost = 0;

	for (int i = 1; i < V; i++)
	{
		//cout << parinte[i] + 1 << " - " << i + 1 << " \t" << graf[i][parinte[i]] << " \n";
		//cout << orase.at(intVec.at(parinte[i])) << " - " << orase.at(intVec.at(i)) << " \t" << graf[i][parinte[i]] << " \n";
		//cout << orase.at(intVec.at(parinte[i])) << " - " << i + 1 << " \t" << graf[i][parinte[i]] << " \n";
		cout << this->orase.at(intVec.at(parinte[i])) << "    ->	" << this->orase.at(intVec.at(i)) << " \n";
		this->drum.push_back(this->orase.at(intVec.at(parinte[i])));
		this->drum.push_back(this->orase.at(intVec.at(i)));

		//cout << parinte[i] + 1 << " ";
		cost += graf[i][parinte[i]];
	}

	this->drum.erase(unique(this->drum.begin(), this->drum.end()), this->drum.end());
	for (size_t i = 0;i < this->drum.size();i++)
		cout << this->drum.at(i) << " -> ";

	y = "drumul are ";
	y.append(to_string(cost));
	y.append(" km");
	cout << y;
	this->drum.push_back(y);
}

void MosCraciun::primalg(int graf[V][V])
{
	int parinte[V];

	int key[V];

	bool vizitat[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, vizitat[i] = false;

	key[0] = 0;
	parinte[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minfunc(key, vizitat);

		vizitat[u] = true;

		for (int v = 0; v < V; v++)

			if (graf[u][v] && vizitat[v] == false && graf[u][v] < key[v])
				parinte[v] = u, key[v] = graf[u][v];
	}

	afisare_graf(parinte, graf);
}