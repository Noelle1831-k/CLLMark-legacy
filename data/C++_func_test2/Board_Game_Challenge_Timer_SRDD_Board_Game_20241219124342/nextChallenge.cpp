void ChallengeManager::nextChallenge() {
    currentChallengeIndex++;
    if (currentChallengeIndex < challenges.size()) {
        cout << "Moving to the next challenge..." << endl;
    } else {
        cout << "All challenges completed!" << endl;
    }
}