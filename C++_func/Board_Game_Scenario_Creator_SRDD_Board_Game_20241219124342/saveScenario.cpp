void FileHandler::saveScenario(Scenario &scenario, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Scenario Saved Data" << endl;
        file.close();
    }
}