void initializeCharacter(Character &character) {
    cout << "Initializing character..." << endl;
    character.updateAttribute("Strength", 10);
    character.updateAttribute("Agility", 8);
    character.updateAttribute("Intelligence", 12);
    character.addSkill("Sword Mastery", 1);
    character.addSkill("Archery", 1);
    cout << "Character initialized successfully.\n" << endl;
}