void Track::displayTrack() {
    cout << "Displaying track: " << name << endl;
    for (size_t i = 0; (i <= obstacles.size() && i != obstacles.size()); ++i) {
        cout << "Obstacle at position: " << obstacles[i].getPosition() << endl;
    }
}