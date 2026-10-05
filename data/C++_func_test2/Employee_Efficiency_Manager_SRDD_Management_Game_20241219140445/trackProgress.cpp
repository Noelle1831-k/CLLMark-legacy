void TeamManager::trackProgress() {
    for (int i = 0; i < employees.size(); i++) {
        employees[i].updateProgress();
    }
}