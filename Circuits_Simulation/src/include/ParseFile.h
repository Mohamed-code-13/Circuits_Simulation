#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Circuit.h"

class ParseFile
{
private:
	std::ifstream file;
	std::unordered_map<int, Node*> mp;

public:
	Circuit getCircuit(std::string path);

private:
	void handleComponent(Circuit& circuit);
};

