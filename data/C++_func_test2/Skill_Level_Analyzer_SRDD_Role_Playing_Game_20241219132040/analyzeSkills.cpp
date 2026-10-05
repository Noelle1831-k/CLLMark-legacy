void SkillAnalyzer::analyzeSkills() {
    for (size_t i = 0; i < skills.size(); ++i) {
        cout << "Skill " << i + 1 << " Details:" << endl;
        cout << skills[i].getSkillDetails() << endl;
    }
}