#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <direct.h>


enum CellType {CT_INT, CT_FLOAT, CT_TEXT, CT_LOGIC, CT_DATE};


class MDColumn
{
	std::string name;
	CellType type;
};

class MDCell
{
	MDColumn * col;
	void * data;
public:
};

class MDRow
{
	std::vector<MDCell> cells;
public:

};
