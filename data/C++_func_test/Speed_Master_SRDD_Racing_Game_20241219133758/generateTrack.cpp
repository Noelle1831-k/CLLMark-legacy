void Track::generateTrack() {
    challenges.clear();
    for (int i = 0; i < difficulty * 3; i++) {
        challenges.push_back("Sharp Turn");
    }
    cout << "Track Generated with " << challenges.size() << " challenges." << endl;
}