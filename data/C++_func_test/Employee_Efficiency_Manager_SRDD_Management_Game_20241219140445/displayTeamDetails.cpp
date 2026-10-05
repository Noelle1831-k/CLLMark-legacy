void TeamManager::displayTeamDetails() {
    cout << "Team Details:" << endl;
    for (int i = 0; i < employees.size(); i++) {
        employees[i].displayEmployeeDetails();
    }
}