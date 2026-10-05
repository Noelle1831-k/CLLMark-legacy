int main() {
    vector<Game> games;
    map<string, Player> players;
    readDataFromFile("data/input.txt", players, games);
    MLModel model;
    vector<vector<float>> features;
    vector<float> labels;
    for (size_t i = 0; i < games.size(); ++i) {
        auto gameFeatures = games[i].generateFeatures();
        for (size_t j = 0; j < gameFeatures.size(); ++j) {
            features.push_back(gameFeatures[j].first);
            labels.push_back(gameFeatures[j].second);
        }
    }
    model.train(features, labels);
    if (!games.empty()) {
        vector<float> predictions = model.predict(games.back().generateFeatures()[0].first);
        cout << "Predicted scores for the last game:" << endl;
        for (size_t i = 0; i < predictions.size(); ++i) {
            cout << "Player " << games.back().getPlayer(i).getName() << ": " << predictions[i] << endl;
        }
    }
    writeDataToFile("data/output.txt", players, games);
    return 0;
}