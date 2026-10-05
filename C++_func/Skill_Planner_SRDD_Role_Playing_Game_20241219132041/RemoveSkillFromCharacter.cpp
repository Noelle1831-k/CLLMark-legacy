void SkillPlanner::RemoveSkillFromCharacter() {
    string charName, skillName;
    cout << "Enter character name: ";
    cin >> charName;
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i].GetName() == charName) {
            cout << "Enter skill name to remove: ";
            cin >> skillName;
            characters[i].RemoveSkill(skillName);
            return;
        }
    }
    cout << "Character " << charName << " not found." << endl;
}