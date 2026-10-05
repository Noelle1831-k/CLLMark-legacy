void Dashboard::removeProject() {
    int projectIndex;
    cout << "Enter project index to remove (0-based): ";
    cin >> projectIndex;
    if (projectIndex >= 0 && projectIndex < projects.size()) {
        projects.erase(projects.begin() + projectIndex);
        cout << "Project removed successfully." << endl;
    } else {
        cout << "Invalid project index." << endl;
    }
}