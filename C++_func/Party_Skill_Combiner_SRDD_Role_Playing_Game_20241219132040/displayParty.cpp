void Party::displayParty() const {
    if (characters.empty()) {
        cout << "The party is empty!" << endl;
        return;
    }
    for (const auto& character : characters) {
        character.displayCharacter();
    }
}