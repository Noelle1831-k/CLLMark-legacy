int Team::getTotalSkillLevel() {
    int totalSkill = 0;
    for (unsigned int i = 0; i < players.size(); ++i) {
        totalSkill += players[i].getSkillLevel();
    }
    return totalSkill;
}