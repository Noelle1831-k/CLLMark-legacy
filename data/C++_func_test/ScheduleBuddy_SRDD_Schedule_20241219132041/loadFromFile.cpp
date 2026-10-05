vector<Event> FileManager::loadFromFile(const string& filename) {
    vector<Event> events;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);
        string name = line.substr(0, pos1);
        string date = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string time = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string description = line.substr(pos3 + 1);
        events.emplace_back(name, date, time, description);
    }
    file.close();
    return events;
}