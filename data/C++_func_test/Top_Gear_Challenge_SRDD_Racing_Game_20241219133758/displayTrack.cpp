void Track::displayTrack() {
    cout << "Track layout: ";
    for (const auto& segment : layout) {
        cout << segment << " ";
    }
    cout << endl;
}