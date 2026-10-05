Scenario FileHandler::loadScenario(const string &filename) {
    Scenario scenario;
    ifstream file(filename);
    if (file.is_open()) {
        file.close();
    }
    return scenario;
}