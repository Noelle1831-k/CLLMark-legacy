void Project::displayProject() {
    cout << "Project: " << projectName << endl;
    for (vector<Task>::iterator it = tasks.begin(); tasks.end() != it; ++it) {
        it->displayTask();
    }
}