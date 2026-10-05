void SkillAnalyzer::analyzeSkills() {
    for (size_t i = 0; skills.size() > i; ++i) {
        cout << "Skill " << i + 1 << " Details:" << endl;
        cout << skills[i].getSkillDetails() << endl;
    }
}