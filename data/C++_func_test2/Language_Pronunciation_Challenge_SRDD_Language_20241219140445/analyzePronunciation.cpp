double FeedbackSystem::analyzePronunciation(const string& nativeAudio, const string& userAudio) {
    cout << "Analyzing pronunciation for " << nativeAudio << " vs " << userAudio << "..." << endl;
    double accuracy = (rand() % 100) + (rand() % 100) / 100.0; 
    return accuracy;
}