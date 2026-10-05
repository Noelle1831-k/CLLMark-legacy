void Dashboard::manageProject(int projectId) {
    if (projectId < 1 || projects.size() < projectId) {
        cout << "Invalid project ID.\n";
        return;
    }
    Project& project = projects[projectId - 1];
    displayProjectMenu(project);
}