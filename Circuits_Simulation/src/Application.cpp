#include <iostream>
#include "include/Circuit.h"
#include "LinearAlgebra/include/algebra.h"

int main()
{
    // Create the circuit
    Circuit circuit;

    // Add nodes to the circuit
    Node* node1 = circuit.addNode(0);
    Node* node2 = circuit.addNode(1);
    Node* node3 = circuit.addNode(2);
    Node* node4 = circuit.addNode(3);

    VoltageSource* vcc1 = circuit.addVoltageSource(24.0, node1, node4);
    VoltageSource* vcc2 = circuit.addVoltageSource(15.0, node3, node4);

    Resistor* r1 = circuit.addResistor(10000.0, node1, node2);
    Resistor* r2 = circuit.addResistor(8100.0, node2, node3);
    Resistor* r3 = circuit.addResistor(4700.0, node2, node4);

    // Calculate the node voltages using MNA
    circuit.simulateCircuit();

    std::cout << "Node 1 voltage: " << node1->getVolt() << " V\n";
    std::cout << "Node 2 voltage: " << node2->getVolt() << " V\n";
    std::cout << "Node 3 voltage: " << node3->getVolt() << " V\n";
    std::cout << "Node 4 voltage: " << node4->getVolt() << " V\n\n";

    std::cout << "Voltage Source 1 voltage: " << vcc1->getVoltageDrop() << " V\n";
    std::cout << "Resistor 1 voltage: " << r1->getVoltageDrop() << " V\n";
    std::cout << "Resistor 2 voltage: " << r2->getVoltageDrop() << " V\n";
    std::cout << "Resistor 3 voltage: " << r3->getVoltageDrop() << " V\n";
	return 0;
}
