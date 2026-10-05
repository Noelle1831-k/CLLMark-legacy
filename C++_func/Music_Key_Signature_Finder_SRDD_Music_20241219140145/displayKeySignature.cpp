void UserInterface::displayKeySignature(const KeySignature &keySignature) {
    cout << "The detected key signature is: " << keySignature.getKey() << endl;
    cout << keySignature.getEducationalResources() << endl;
}