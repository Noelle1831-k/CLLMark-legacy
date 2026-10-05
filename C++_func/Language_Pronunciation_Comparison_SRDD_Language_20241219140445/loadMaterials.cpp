void PracticeMaterial::loadMaterials(const string& filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        phrases.push_back(line);
    }
    file.close();
}