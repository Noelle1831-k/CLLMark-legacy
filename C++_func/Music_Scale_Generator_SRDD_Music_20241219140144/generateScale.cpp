vector<string> ScaleGenerator::generateScale(const string &rootNote, const string &scaleType) {
    vector<int> intervals;
    if (scaleType == "major") {
        intervals = {2, 2, 1, 2, 2, 2, 1};
    } else if (scaleType == "minor") {
        intervals = {2, 1, 2, 2, 1, 2, 2};
    } else if (scaleType == "pentatonic") {
        intervals = {2, 2, 3, 2, 3};
    } else {
        return {};
    }
    vector<string> scale;
    int startIndex = noteMap[rootNote];
    scale.push_back(rootNote);
    for (int i = 0; i < intervals.size(); i++) {
        startIndex = (startIndex + intervals[i]) % noteSequence.size();
        scale.push_back(noteSequence[startIndex]);
    }
    return scale;
}