void SkillPlanner::AddSkillToCharacter() {
    string charName, skillName, skillType;
    int levelReq;
    cout << "Enter character name: ";
    cin >> charName;
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i].GetName() == charName) {
            cout << "Enter skill name: ";
            cin >> skillName;
            cout << "Enter skill type: ";
            cin >> skillType;
            cout << "Enter skill level requirement: ";
            cin >> levelReq;
            if (levelReq < 1) {
                cout << "Invalid level requirement. Must be at least 1." << endl;
                return;
            }
            Skill skill(skillName, skillType, levelReq);
            characters[i].AddSkill(skill);
            return;
        }
    }
    cout << "Character " << charName << " not found." << endl;
}