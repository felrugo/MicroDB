#include "MDDatabase.h"

MDDatabase::MDDatabase(std::string sname)
{
	name = sname;
	floc = name + "/" + name + ".mdb";
	tabs.clear();
	//exists?
	std::ifstream file;
	file.open(floc);
	if (file.is_open())
	{
		file.close();
	}
	else
	{
		std::ofstream nf;
		nf.open(floc);
		nf.close();
	}
}


void MDDatabase::Load(std::string file)
{
	floc = file;
}



void MDDatabase::Save()
{

}