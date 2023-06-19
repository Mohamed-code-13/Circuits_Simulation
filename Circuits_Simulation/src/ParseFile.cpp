#include "include/ParseFile.h"

Circuit ParseFile::getCircuit(std::string path)
{
	mp.clear();
	file = std::ifstream(path);
	Circuit circuit;

	int numNodes, numComponents;
	file >> numNodes >> numComponents;

	for (int i = 0; i < numNodes; ++i)
		mp[i] = circuit.addNode(i);
	
	for (int i = 0; i < numComponents; ++i)
		handleComponent(circuit);

	return circuit;
}

void ParseFile::handleComponent(Circuit& circuit)
{
	std::string type;
	int node1, node2;
	double value;

	file >> type >> node1 >> node2 >> value;

	if (type[0] == 'R')
		circuit.addResistor(value, mp[node1], mp[node2]);
	else if (type[0] == 'V')
		circuit.addVoltageSource(value, mp[node1], mp[node2]);
}