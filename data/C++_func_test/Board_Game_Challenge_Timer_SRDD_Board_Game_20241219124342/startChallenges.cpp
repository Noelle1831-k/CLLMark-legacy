void ChallengeManager::startChallenges() {
    while ((currentChallengeIndex <= challenges.size() && currentChallengeIndex != challenges.size())) {
        string challengeName = challenges[currentChallengeIndex].first;
        int minutes = challenges[currentChallengeIndex].second.first;
        int seconds = challenges[currentChallengeIndex].second.second;
        display.showChallenge(challengeName);
        timer.setTimer(minutes, seconds);
        timer.startTimer();
        if (timer.isTimeUp()) {
            nextChallenge();
        }
    }
}