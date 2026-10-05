void FileManager::saveToFile(const string& filename, const vector<Event>& events) {
    ofstream file(filename);
    for (const auto& event : events) {
        file << event.getName() << "|" << event.getDate() << "|" << event.getTime() << "|" << event.getDescription() << endl;
    }
    file.close();
}