#include "Doamna_Craciun.h"
void Doamna_Craciun::afisare_orase_d()
{
	cout << "\nDrumul dat doamnei Craciun : " << endl;

	for (size_t i = 0;i < this->orase_d.size();i++)
		cout << this->orase_d.at(i) << " -> ";
}
void Doamna_Craciun::set_orase(vector<string> oras)
{
	this->orase_d = oras;
}
void Doamna_Craciun::set_carbuni_d(trol obj)
{
	this->numarCarbuni = obj.get_carbune();
}

void Doamna_Craciun::set_acadele_d(elf object)
{
	this->numarAcadele = object.get_acadele();
}
int Doamna_Craciun::get_Carbuni()
{
	return this->numarCarbuni;
}
int Doamna_Craciun::get_Acadele()
{
	return this->numarAcadele;
}
Doamna_Craciun::~Doamna_Craciun()
{
	this->Lista_Doamna_Craciun.clear();
	this->orase_d.clear();
}

void Doamna_Craciun::Afisare_Buget_Extra()
{
	double Buget = 0;
	Buget = this->get_Acadele() * 1 + this->get_Carbuni() * 0.5;
	cout << endl;
	cout << "Bugetul extra este " << Buget << "$" << endl;
}