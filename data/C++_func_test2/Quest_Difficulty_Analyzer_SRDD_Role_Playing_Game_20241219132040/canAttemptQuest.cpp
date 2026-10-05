bool Player::canAttemptQuest(const Quest &quest) const {
    int difficulty = quest.getEnemyStrength() + quest.getRequiredSkills() + quest.getTimeConstraints();
    return (level + resources) >= difficulty;
}