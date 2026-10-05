bool Track::generateTrack() {
    cout << "Generating track...\n";
    layout.clear();
    for (int i = 0; i < trackLength; ++i) {
        if (rand() % 20 == 0) {
            layout.push_back("Obstacle");
        } else if (rand() % 50 == 0) {
            layout.push_back("Puzzle");
        } else {
            layout.push_back("Track");
        }
    }
    cout << "Track generated with " << numObstacles << " obstacles.\n";
    return true;
}