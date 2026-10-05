void MoodAnalyzer::determineMood(const vector<float>& tempo, const vector<string>& key,
                                 const vector<string>& instrumentation, const vector<string>& harmonicStructure) {
    if (!tempo.empty() && tempo[0] > 100.0f) {
        mood = "Energetic";
    } else {
        mood = "Calm";
    }
    if (!key.empty() && key[0] == "C Major") {
        mood += " and Happy";
    } else {
        mood += " and Sad";
    }
}