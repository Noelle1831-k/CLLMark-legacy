std::vector<std::string> RecommendationEngine::generateRecommendations(const UserProfile& userProfile, const MusicLibrary& musicLibrary) {
    std::vector<std::string> recommendations;
    auto preferences = userProfile.getPreferences();
    for (auto it = preferences.begin(); it != preferences.end(); ++it) { 
        auto songs = musicLibrary.getSongsByGenre(it->first);
        for (int i = 0; i < songs.size(); i++) { 
            recommendations.push_back(songs[i]);
        }
    }
    return recommendations;
}