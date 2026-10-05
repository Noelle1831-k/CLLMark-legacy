int main(void) {
    City city;
    Simulation simulation(city);
    city.addRoad("Main Street", 500, 3);
    city.addTrafficSignal("Main Street", "1st Avenue");
    city.addPublicTransport("Bus", "Route 1");
    simulation.startSimulation();
    return 0;
}