void Simulation::initialize() {
    cout << "Initializing simulation..." << endl;
    teamManager.addEmployee(Employee("Alice", "Developer", 80));
    teamManager.addEmployee(Employee("Bob", "Designer", 75));
    teamManager.addTask(Task("Develop Feature X", "2023-12-01"));
    teamManager.addTask(Task("Design UI for Feature Y", "2023-12-05"));
}