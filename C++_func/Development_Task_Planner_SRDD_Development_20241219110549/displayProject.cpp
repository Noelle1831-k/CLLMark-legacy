void Project::displayProject() {
    cout << "Project: " << projectName << endl;
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        it->displayTask();
    }
}