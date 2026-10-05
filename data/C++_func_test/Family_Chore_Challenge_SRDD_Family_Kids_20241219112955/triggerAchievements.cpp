void triggerAchievements() {
        for (auto& achievement : achievements) {
            achievement.second->checkEligibility(*this);
        }
    }