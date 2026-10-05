float AudioComparator::analyzePronunciation(const string& userFile, const string& nativeFile) {
    cout << "Comparing user file: " << userFile << " with native file: " << nativeFile << endl;
    float similarityScore = static_cast<float>(rand() % 100) / 100.0; 
    cout << "Similarity Score: " << similarityScore << endl;
    return similarityScore;
}