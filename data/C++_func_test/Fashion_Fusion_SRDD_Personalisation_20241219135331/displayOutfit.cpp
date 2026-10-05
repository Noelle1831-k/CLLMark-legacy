void Outfit::displayOutfit() const {
    printf("Outfit: ");
    for (vector<string>::const_iterator it = components.begin(); it != components.end(); ++it) {
        cout << *it << " ";
    }
    printf("\n");
}