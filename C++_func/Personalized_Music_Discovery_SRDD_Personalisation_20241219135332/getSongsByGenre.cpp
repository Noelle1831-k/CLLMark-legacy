std::vector<std::string> MusicLibrary::getSongsByGenre(const std::string& genre) const {
    auto it = musicDatabase.find(genre);
    if (it != musicDatabase.end()) {
        return it->second;
    }
    return {};
}