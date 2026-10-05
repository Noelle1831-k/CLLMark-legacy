void SkillAnalyzer::suggestSkills(const Player& player) {
    cout << "Skills you can learn:" << endl;
    for (const auto& skill : skills) {
        if (player.canLearnSkill(skill)) {
            cout << skill.getSkillDetails() << endl;
        }
    }
}