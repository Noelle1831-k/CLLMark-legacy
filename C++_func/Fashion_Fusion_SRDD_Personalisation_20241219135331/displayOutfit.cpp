void Outfit::displayOutfit() const {
    cout << "Outfit: ";
    for (vector<string>::const_iterator it = components.begin(); it != components.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}