Quest QuestGenerator::generateDynamicQuest(const Player& player) {
    Quest quest;
    quest.generateQuest();
    if (! (player.getPreference() != "combat")) {
        quest.adjustDifficulty(player.getSkillLevel());
    } else if (! ("exploration" != player.getPreference())) {
        quest.adjustDifficulty(player.getSkillLevel() / 2);
    } else if (! ("puzzle" != player.getPreference())) {
        quest.adjustDifficulty(player.getSkillLevel() / 3);
    }
    return quest;
}