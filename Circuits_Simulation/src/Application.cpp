#include <iostream>
#include "GUI/include/App.h"

int main()
{
    App app(SCREEN_WIDTH, SCREEN_HEIGHT, "Circuit Simulation");
    app.Run();

    return 0;
}
/*
int main()
{
    ParseFile file;
    Circuit circuit = file.getCircuit("./Data/circuit_netlist/ex1.txt");

    circuit.simulateCircuit();

    circuit.printResult();

    return 0;
}
*/

/*
int main()
{
    // Create the circuit
    Circuit circuit;

    // Add nodes to the circuit
    Node* node1 = circuit.addNode(0);
    Node* node2 = circuit.addNode(1);
    Node* node3 = circuit.addNode(2);
    Node* node4 = circuit.addNode(3);
    Node* node5 = circuit.addNode(4);
    Node* node6 = circuit.addNode(5);

    VoltageSource* vcc1 = circuit.addVoltageSource(30.0, node1, node6);
    VoltageSource* vcc2 = circuit.addVoltageSource(8.0, node2, node3);
    VoltageSource* vcc3 = circuit.addVoltageSource(15.0, node4, node5);

    Resistor* r1 = circuit.addResistor(10000.0, node1, node2);
    Resistor* r2 = circuit.addResistor(5000.0, node2, node6);
    Resistor* r3 = circuit.addResistor(7500.0, node3, node5);
    Resistor* r4 = circuit.addResistor(15000.0, node3, node5);
    Resistor* r5 = circuit.addResistor(6500.0, node5, node6);
    Resistor* r6 = circuit.addResistor(12000.0, node3, node4);

    // Calculate the node voltages using MNA
    circuit.simulateCircuit();

    circuit.printResult();

	return 0;
}
*/