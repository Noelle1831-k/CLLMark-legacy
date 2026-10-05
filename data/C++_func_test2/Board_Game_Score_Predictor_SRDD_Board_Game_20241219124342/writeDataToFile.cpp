void writeDataToFile(const string& filePath, const map<string, Player>& players, const vector<Game>& games) {
    ofstream file(filePath);
    if (!file.is_open()) return;
    for (const auto& [name, player] : players) {
        file << name << " ";
        file << player.getStrategyScore() << endl;
    }
    file.close();
}