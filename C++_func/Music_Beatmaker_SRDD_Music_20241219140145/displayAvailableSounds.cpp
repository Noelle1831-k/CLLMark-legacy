void BeatMaker::displayAvailableSounds() const {
    cout << "Available sounds:" << endl;
    for (int i = 0; i < sounds.size(); i++) {
        cout << i << ": " << sounds[i].getName() << endl;
    }
}