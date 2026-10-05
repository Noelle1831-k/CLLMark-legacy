void Party::removeCharacter(const string& name) {
    auto it = remove_if(characters.begin(), characters.end(),
                        [&name](const Character& c) { return c.getName() == name; });
    if (it != characters.end()) {
        characters.erase(it, characters.end());
        cout << "Character removed successfully!" << endl;
    } else {
        cout << "Character not found!" << endl;
    }
}