void Track::displayTrack() {
    cout << "Track layout: ";
    for (int i = 0; i < layout.size(); i++) {
        cout << layout[i] << " ";
    }
    cout << endl;
}