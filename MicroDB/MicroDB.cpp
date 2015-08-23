// MicroDB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MDSystem.h"

int main()
{
	MDSystem dbsys;
	dbsys.CreateDB("Test");
    return 0;
}

