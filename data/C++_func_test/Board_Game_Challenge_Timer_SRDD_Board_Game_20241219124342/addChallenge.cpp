void ChallengeManager::addChallenge(string challengeName, int minutes, int seconds) {
    challenges.push_back(make_pair(challengeName, make_pair(minutes, seconds)));
}