void UserProfile::addPreference(const std::string& genre, const std::string& artist) {
    preferences[genre].push_back(artist);
}