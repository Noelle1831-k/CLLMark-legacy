void Track::loadTrack(string file) {
    ifstream infile(file);
    string line;
    while (getline(infile, line)) {
        trackData.push_back(line);
    }
    infile.close();
}