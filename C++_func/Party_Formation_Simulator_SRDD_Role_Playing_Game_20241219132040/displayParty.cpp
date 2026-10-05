void UIHandler::displayParty(Party &party) {
    vector<Character> characters = party.getCharacters();
    cout << "\nCurrent Party:" << endl;
    for (auto &character : characters) {
        cout << character.getName() << " (" << character.getClass() << ")" << endl;
    }
}