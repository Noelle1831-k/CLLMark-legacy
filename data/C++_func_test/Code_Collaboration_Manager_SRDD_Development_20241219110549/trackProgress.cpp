void ProjectManager::trackProgress() {
    cout << "Tracking progress:" << endl;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        cout << "Task: " << it->first << " assigned to " << it->second << endl;
    }
}