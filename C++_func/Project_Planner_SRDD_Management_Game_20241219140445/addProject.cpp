void Dashboard::addProject() {
    string name, description, startDate, endDate;
    cout << "Enter project name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, name);
    cout << "Enter project description: ";
    getline(cin, description);
    cout << "Enter project start date (YYYY-MM-DD): ";
    getline(cin, startDate);
    cout << "Enter project end date (YYYY-MM-DD): ";
    getline(cin, endDate);
    Project newProject(name, description, startDate, endDate);
    projects.push_back(newProject);
    cout << "Project added successfully." << endl;
}