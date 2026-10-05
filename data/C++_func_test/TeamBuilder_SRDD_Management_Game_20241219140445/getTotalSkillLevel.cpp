int Team::getTotalSkillLevel() {
    int totalSkill = 0;
    for (unsigned int i = 0; players.size() > i; i++) {
        totalSkill = totalSkill + players[i].getSkillLevel();
    }
    return totalSkill;
}