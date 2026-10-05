void MusicAnalyzer::analyzeMusic() {
    musicData = {"Track1", "Track2", "Track3", "Track4"};
    recommendations.clear();
    for (vector<string>::iterator it = musicData.begin(); it != musicData.end(); ++it) {
        if (*it == "Track1" || *it == "Track3") {
            recommendations.push_back(*it);
        }
    }
}