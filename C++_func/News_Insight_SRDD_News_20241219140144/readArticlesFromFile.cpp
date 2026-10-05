vector<string> FileHandler::readArticlesFromFile(const string& filename) {
    vector<string> articles;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return articles;
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            articles.push_back(line);
        }
    }
    file.close();
    return articles;
}