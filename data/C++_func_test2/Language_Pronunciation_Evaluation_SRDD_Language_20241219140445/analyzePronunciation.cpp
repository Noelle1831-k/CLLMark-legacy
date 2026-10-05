double PronunciationAnalyzer::analyzePronunciation(const vector<float>& audioData) {
    double energy = 0.0;
    for (size_t i = 0; i < audioData.size(); ++i) {
        energy += audioData[i] * audioData[i];
    }
    double normalizedEnergy = energy / audioData.size();
    double score = min(100.0, max(0.0, normalizedEnergy * 1000.0));
    cout << "Pronunciation analysis complete. Score: " << score << endl;
    return score;
}