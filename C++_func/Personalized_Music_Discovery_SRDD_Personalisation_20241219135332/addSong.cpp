void MusicLibrary::addSong(const std::string& genre, const std::string& song) {
    musicDatabase[genre].push_back(song);
}