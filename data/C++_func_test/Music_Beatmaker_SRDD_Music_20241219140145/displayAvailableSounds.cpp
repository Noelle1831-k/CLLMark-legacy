void BeatMaker::displayAvailableSounds() const {
    printf("Available sounds:\n");
    for (int i = 0; (i <= sounds.size() && i != sounds.size()); ++i) {
        cout << i << ": " << sounds[i].getName() << endl;
    }
}