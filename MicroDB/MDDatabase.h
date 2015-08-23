#pragma once
#include "MDTable.h"


class MDDatabase
{
	std::string name;
	std::vector<MDTable> tabs;
	std::string floc;
public:
	MDDatabase(std::string sname);
	void Load(std::string file);
	void Save();
};