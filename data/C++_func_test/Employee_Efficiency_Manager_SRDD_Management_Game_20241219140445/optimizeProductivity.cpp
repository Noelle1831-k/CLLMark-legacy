void TeamManager::optimizeProductivity() {
    cout << "Analyzing team productivity..." << endl;
    for (int i = 0; i < employees.size(); i++) {
        cout << "Employee: " << employees[i].getName() << ", Productivity Level: " << employees[i].getProductivityLevel() << endl;
    }
}