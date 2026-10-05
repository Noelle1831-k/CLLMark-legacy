void TeamManager::displayFreeAgents() {
    cout << "Available Free Agents:" << endl;
    for (size_t i = 0; i < freeAgents.size(); ++i) {
        cout << i + 1 << ". ";
        freeAgents[i].stats();
    }
}