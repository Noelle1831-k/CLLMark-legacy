Character UIHandler::inputCharacterDetails() {
    string name, characterClass;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter character class (Melee/Ranged/Magic): ";
    cin >> characterClass;
    Character character(name, characterClass);
    int numSkills, numAbilities;
    cout << "Enter number of skills: ";
    cin >> numSkills;
    for (int i = 0; i < numSkills; ++i) {
        string skill;
        int level;
        cout << "Enter skill name and level: ";
        cin >> skill >> level;
        character.addSkill(skill, level);
    }
    cout << "Enter number of abilities: ";
    cin >> numAbilities;
    for (int i = 0; i < numAbilities; ++i) {
        string ability;
        int power;
        cout << "Enter ability name and power: ";
        cin >> ability >> power;
        character.addAbility(ability, power);
    }
    return character;
}