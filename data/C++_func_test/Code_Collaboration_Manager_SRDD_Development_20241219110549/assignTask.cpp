void ProjectManager::assignTask(string task, string developer) {
    tasks[task] = developer;
    cout << "Assigned task: " << task << " to " << developer << endl;
}