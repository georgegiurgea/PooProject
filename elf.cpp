#include "elf.h"

int elf::get_acadele()
{
	return this->numar_acadele;
}
vector<vector<string>> elf::get_Lista_ref()
{
	return this->lista_ref;
}
void elf::set_up()
{
	this->Lista = get_date();
	this->lin_Lista = get_lines_input();
	this->col_Lista = get_col_input();
}
vector<string> elf::orase()
{
	this->oras.clear();
	try {
		for (size_t i = 0;i < this->lista_ref.at(0).size();i++)
		{
			this->oras.push_back(this->lista_ref.at(i).at(2));
		}
		return oras;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of range : " << oor.what() << '\n';
	}
}
void elf::afisare_input()
{
	MosCraciun::afisare_csv(this->Lista, this->lin_Lista, this->col_Lista);
}
void elf::afisare_inv()
{
	MosCraciun::afisare_csv(this->inv, this->lin_inv, this->col_inv);
}
void elf::citire_inv(string nume)
{
	vector<string> v;
	this->Lista.clear();
	v.clear();
	this->col_inv = 0;
	try {
		ifstream in;

		in.open(nume);
		if (!in)throw 2;
		string line, field;

		this->lin_inv = 0;

		while (getline(in, line))
		{
			this->col_inv = v.size();
			v.clear();

			stringstream ss(line);
			++this->lin_inv;
			while (getline(ss, field, ','))
			{
				v.push_back(field);
			}
			this->inv.push_back(v);
		}

		in.close();
	}
	catch (int z) {
		cout << "Fisierul nu se deschide \Elfi" << endl;
	}
}
elf::elf()
{
	set_up();
}

elf::~elf()
{
	this->Lista.clear();
	this->inv.clear();
	this->lista_ref.clear();
	this->oras.clear();
	this->status.clear();
}
vector<string> elf::spargere_cuv(string aux2)
{
	vector<string> rez;
	stringstream iss(aux2);

	while (iss.good())
	{
		string substr;
		getline(iss, substr, '|');
		rez.push_back(substr);
	}

	return rez;
}

void elf::functie()
{
	string aux;
	vector<string> rezultat;
	vector<int> iteme;
	int total = 0;
	int index = 0;
	int aux2 = 0;
	int index2 = 0;
	string str;
	string final;
	vector<string> spart;
	set_up();
	cout << this->lin_inv;
	for (size_t i = 0;i < this->lin_inv;i++)
	{
		for (size_t j = 0;j < this->col_inv;j++)
			cout << this->inv[i][j] << " ";
		cout << endl;
	}

	//Lista[i][3]
	//parcurge copii
	for (int i = 0;i < this->lin_Lista;i++)
	{//verifaca status
		if (this->status.at(i) == 1)
		{
			aux.clear();
			aux.append(this->Lista.at(i).at(3));

			rezultat = spargere_cuv(aux);

			//parcurge lista dorinte pt copil i
			for (size_t j = 0;j < rezultat.size();j++)
			{//parcurge inventar pentru copil i
				for (size_t k = 0;k < this->lin_inv;k++)

				{
					if (rezultat[j].compare(this->inv[k][0]) == 0)
					{
						total += stoi(this->inv[k][1]);
						iteme.push_back(k);

						if (total <= 100)
						{
							index++;
							if (str.size() == 0)
								str.append(this->inv[k][0]);
							else
							{
								str.append("|");
								str.append(this->inv[k][0]);
							}
						}
						else
						{
							index2++;
						}
					}
				}
			}

			if (total >= 101)
				for (int i = index;i < iteme.size();i++)
					total -= stoi(this->inv[iteme.at(i)][1]);

			//cout << endl;
			/*
			cout << i + 1 << endl;
			cout << "index : " << index << endl;
			cout << "index2 : " << index2 << endl;
			cout << "total " << total << endl;*/
			if (index2 != 0 && total == 0)
			{
				//cout << "cadou defaul de 100$" << endl;
				str.append("MP3 player");
				total = 100;
			}
			if (index == 0 && index2 == 0 && total == 0)
			{
				//cout << "NU SE GEASTE NIMIC DIN LISTA DE DORINTE PRIMESTE CADOU DEFAUL$" << endl;
				str.append("MP3 player");
				total = 100;
			}
			if (this->status.at(i) == 1 && total != 0) {
				numar_acadele += (100 - total);

				if (total != 100) {
					str.append("|");
					str.append(to_string(100 - total));
					str.append(" acadele");
				}
			}
		}

		else
		{
			//cout << "Copil rau primeste cadou de 10$" << endl;
			str.append("Nuia");
			total = 10;
		}

		spart.push_back(to_string(i + 1));

		spart.push_back(this->Lista[i][0]);

		spart.push_back(this->Lista[i][2]);

		spart.push_back(str);

		spart.push_back(this->Lista[i][4]);

		spart.push_back(to_string(total));

		this->lista_ref.push_back(spart);

		if (this->Lista[i][4].compare("roz") == 0)
		{
			for (size_t i = 0;i < spart.size();i++)

				cout << "\x1B[95m" << spart.at(i) << "," << "\033[0m";
			cout << endl;
		}

		else if (this->Lista[i][4].compare("blue") == 0)
		{
			for (size_t i = 0;i < spart.size();i++)

				cout << "\x1B[94m" << spart.at(i) << "," << "\033[0m";
			cout << endl;
		}

		iteme.clear();
		spart.clear();
		cout << endl;
		str.clear();
		final.clear();
		total = 0;
		index = 0;
		index2 = 0;
		rezultat.clear();

		cout << endl;
	}

	cout << this->numar_acadele << endl;
}