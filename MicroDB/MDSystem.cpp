#include "MDSystem.h"


MDSystem::MDSystem()
{
	std::ifstream dblist;
	dblist.open(".dblist");
	if (!dblist.is_open())
	{
		std::ofstream ndblist;
		ndblist.open(".dblist");
		ndblist.close();
		dblist.close();
	}
}


void MDSystem::ScanDBs()
{
	std::ifstream dbl;
	dbl.open(".dblist");
	if (dbl.is_open())
	{
		while (!dbl.eof())
		{
			std::string buf;
			dbl >> buf;

			MDDatabase * db = new MDDatabase(buf);


		}
		dbl.close();
	}
}


bool MDSystem::DBexists(std::string name)
{
	std::ifstream dbl;
	dbl.open(".dblist");
	if (dbl.is_open())
	{
		while (!dbl.eof())
		{
			std::string buf;
			dbl >> buf;
			if (buf == name)
			{
				dbl.close();
				std::ifstream s;
				s.open(name + "/" + name + ".mdb");
				if (s.is_open())
					s.close();
					return true;
			}
		}
		dbl.close();
		return false;
	}
	return false;
}

void MDSystem::CreateDB(std::string name)
{
	if (!DBexists(name))
	{
		std::ofstream dblist;
		dblist.open(".dblist", std::ifstream::app);
		if (dblist.is_open())
		{
			dblist << name << std::endl;
			dblist.close();
		}
		_mkdir(name.c_str());
		dblist.open(name + "/" + name + ".mdb");
		if (dblist.is_open())
			dblist.close();
	}
}



unsigned int MDSystem::GetCID(std::string s, CPS c)
{
	std::string Ps[] = { "CREATE", "SELECT", "DELETE", "SET", "INSERT"};
	std::string Ss[] = { "DB", "TABLE", "FROM", "INTO" };
	std::string Ts[] = { "WHERE", "VALUES" };
	std::string OPs[] = {"+", "-", "*", "/" };

	switch (c)
	{

	case MC_P:
		for (size_t i = 0; i < 5; i++)
		{
			if (s == Ps[i])
				return i;
		}
		break;

	case MC_S:
		for (size_t i = 0; i < 4; i++)
		{
			if (s == Ss[i])
				return i;
		}
		break;

	default:
		break;
	}
	return -1;
}



bool MDSystem::Quary(std::string qcmd)
{
	std::stringstream ss;
	ss.str(qcmd);
	std::string buf;
	ss >> buf;
	switch (GetCID(buf, MC_P))
	{
	case 0:
		ss >> buf;
		switch (GetCID(buf, MC_S))
		{
		case 0:
			break;
		case 1:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}