void SystemManager::listSessions() {
    cout << "Listing all sessions:" << endl;
    for (int i = 0; i < sessions.size(); i++) {
        sessions[i].displaySession();
    }
}