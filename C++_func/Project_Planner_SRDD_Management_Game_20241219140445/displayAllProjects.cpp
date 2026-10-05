void Dashboard::displayAllProjects() {
    cout << "All Projects:" << endl;
    if (projects.empty()) {
        cout << "No projects available." << endl;
    } else {
        for (int i = 0; i < projects.size(); i++) {
            cout << i + 1 << ". ";
            projects[i].displayProjectDetails();
        }
    }
}