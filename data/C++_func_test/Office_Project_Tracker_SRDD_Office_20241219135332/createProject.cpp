void Dashboard::createProject(string name, string deadline, string description) {
    Project newProject(name, deadline, description);
    projects.push_back(newProject);
    cout << "Project created successfully!\n";
}