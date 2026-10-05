void readDataFromFile(const string& filePath, map<string, Player>& players, vector<Game>& games) {
    ifstream file(filePath);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string playerName;
        ss >> playerName;
        if (players.find(playerName) == players.end()) {
            players[playerName] = Player(playerName);
        }
        int score;
        while (ss >> score) {
            players[playerName].addScore(score);
        }
    }
    file.close();
}