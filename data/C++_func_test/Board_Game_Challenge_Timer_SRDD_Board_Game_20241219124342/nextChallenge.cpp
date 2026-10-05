void ChallengeManager::nextChallenge() {
    ++currentChallengeIndex;
    if (challenges.size() > currentChallengeIndex) {
        cout << "Moving to the next challenge..." << endl;
    } else {
        cout << "All challenges completed!" << endl;
    }
}