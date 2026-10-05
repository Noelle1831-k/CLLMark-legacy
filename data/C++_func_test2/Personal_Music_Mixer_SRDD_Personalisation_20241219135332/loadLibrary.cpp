void MusicLibrary::loadLibrary(const string& path) {
    ifstream file(path.c_str());
    string song;
    while (getline(file, song)) {
        songs.push_back(song);
    }
    file.close();
}