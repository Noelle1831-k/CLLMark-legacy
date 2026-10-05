Quest QuestGenerator::generateDynamicQuest(const Player& player) {
    Quest quest;
    quest.generateQuest();
    if (player.getPreference() == "combat") {
        quest.adjustDifficulty(player.getSkillLevel());
    } else if (player.getPreference() == "exploration") {
        quest.adjustDifficulty(player.getSkillLevel() / 2);
    } else if (player.getPreference() == "puzzle") {
        quest.adjustDifficulty(player.getSkillLevel() / 3);
    }
    return quest;
}