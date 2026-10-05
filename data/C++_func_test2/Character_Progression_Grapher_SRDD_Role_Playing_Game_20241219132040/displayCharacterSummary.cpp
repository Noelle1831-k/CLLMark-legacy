void Character::displayCharacterSummary() const {
    cout << "Character Summary:" << endl;
    cout << "Attributes:" << endl;
    for (map<string, int>::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
        cout << "- " << it->first << ": " << it->second << endl;
    }
    cout << "Skills:" << endl;
    for (map<string, int>::const_iterator it = skills.begin(); it != skills.end(); ++it) {
        cout << "- " << it->first << ": " << it->second << endl;
    }
    cout << "Equipment:" << endl;
    for (map<string, string>::const_iterator it = equipment.begin(); it != equipment.end(); ++it) {
        cout << "- " << it->first << ": " << it->second << endl;
    }
}