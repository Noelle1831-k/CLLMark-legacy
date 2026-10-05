vector<string> FileManager::loadMix(const string& filename) {
    ifstream file(filename.c_str());
    vector<string> mix;
    string song;
    while (getline(file, song)) {
        mix.push_back(song);
    }
    file.close();
    return mix;
}