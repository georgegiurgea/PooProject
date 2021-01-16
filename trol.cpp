#include "trol.h"

trol::trol()
{
}

trol::~trol()
{
	this->lista_trol.clear();
	//cout << "troll distrus" << endl;
}
void trol::set_list_Tr(elf& obj)
{
	this->lista_trol = obj.get_Lista_ref();
}

void trol::afisare_lista()
{
	for (size_t i = 0;i < lista_trol[0].size();i++)
	{
		for (size_t j = 0;j < lista_trol.size();j++)
			cout << lista_trol.at(i).at(j) << " ";
		cout << endl;
	}
}

int trol::get_carbune()
{
	return this->carbune;
}

void trol::pachet()
{
	string s;
	for (size_t i = 0;i < lista_trol[0].size();i++)
	{	//roz sau albastrucout << this->lista_trol.at(i).at(4) << " ";
		if (this->lista_trol.at(i).at(4).compare("roz") == 0)this->roz++;
		else if (this->lista_trol.at(i).at(4).compare("blue") == 0)this->blue++;
		//cadou cout << this->lista_trol.at(i).at(3) << " ";
		if (this->lista_trol.at(i).at(3).compare("Nuia") == 0)
		{
			this->carbune++;
			s.append("Nuia");
			s.append("|");
			s.append("Carbune");
			this->lista_trol.at(i).at(3) = s;
		}
	}
	cout << "\x1B[94m" << "Ambalaj pachet albastru : " << this->blue << "\033[0m" << endl;
	cout << "\x1B[95m" "Ambalaj pachet roz : " << this->roz << "\033[0m" << endl;
	cout << "carbuni " << this->carbune;
}