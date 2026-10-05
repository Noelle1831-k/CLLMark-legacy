void Track::generateTrack() {
    layout.clear();
    for (int i = 0; i < 100; i++) {
        layout.push_back(Utils::randomInt(0, 2)); 
    }
    cout << "Track generated with " << layout.size() << " segments." << endl;
}