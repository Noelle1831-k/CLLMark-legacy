void Dashboard::listProjects() {
    if (projects.empty()) {
        cout << "No projects available.\n";
        return;
    }
    cout << "\n--- List of Projects ---\n";
    for (size_t i = 0; i < projects.size(); ++i) {
        cout << "ID: " << i + 1 << ", Name: " << projects[i].getName() << "\n";
    }
}