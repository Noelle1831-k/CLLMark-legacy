void RaceTrack::generateTrack() {
    cout << "Generating track..." << endl;
    obstacles.clear();
    for (int i = 0; i < 10; ++i) {
        obstacles.push_back(rand() % finishLine);
    }
}