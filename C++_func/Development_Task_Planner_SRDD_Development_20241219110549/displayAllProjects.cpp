void TaskPlanner::displayAllProjects() {
    for (vector<Project>::iterator projIt = projects.begin(); projIt != projects.end(); ++projIt) {
        projIt->displayProject();
    }
}