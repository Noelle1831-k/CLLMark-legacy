void Dashboard::addProject() {
    string description;
    string startDate;
    string endDate;
    string name;
    
    printf("Enter project name: ");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, name);
    printf("Enter project description: ");
    getline(cin, description);
    printf("Enter project start date (YYYY-MM-DD): ");
    getline(cin, startDate);
    printf("Enter project end date (YYYY-MM-DD): ");
    getline(cin, endDate);
    Project newProject(name, description, startDate, endDate);
    projects.push_back(newProject);
    printf("Project added successfully.\n");
}