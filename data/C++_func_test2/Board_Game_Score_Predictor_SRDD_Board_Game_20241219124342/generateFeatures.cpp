vector<pair<vector<float>, float>> Game::generateFeatures() const {
    vector<pair<vector<float>, float>> features;
    for (size_t i = 0; i < playerList.size(); ++i) {
        vector<float> playerFeatures = {playerList[i].getStrategyScore(), static_cast<float>(numPlayers)};
        features.emplace_back(playerFeatures, 0); 
    }
    return features;
}