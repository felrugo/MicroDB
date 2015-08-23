#pragma once

#include "MDTElements.h"

class MDDatabase;

class MDTable
{
	std::string name;
	std::string floc;
	MDDatabase * container;
	std::vector<MDColumn> cols;

public:
	MDTable(std::string name);
	void Load(std::string file);
	void Save();
};