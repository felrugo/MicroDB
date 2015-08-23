#pragma once

#include "MDDatabase.h"

class MDSystem
{
	std::vector<MDDatabase*> dbs;
	MDDatabase * selected;
	enum CPS { MC_P, MC_S, MC_T, MC_OPERATOR, MC_LOGIC };
	unsigned int GetCID(std::string s, CPS c);
	void ScanDBs();
	bool DBexists(std::string name);

public:
	MDSystem();
	void CreateDB(std::string name);
	bool Quary(std::string qcmd);
};
