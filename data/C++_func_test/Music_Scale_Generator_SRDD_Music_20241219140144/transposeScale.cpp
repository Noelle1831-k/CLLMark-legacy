vector<string> ScaleGenerator::transposeScale(const vector<string> &scale, int steps) {
    vector<string> transposedScale;
    for (int i = 0; i < scale.size(); i++) {
        int index = (noteMap[scale[i]] + steps + noteSequence.size()) % noteSequence.size();
        transposedScale.push_back(noteSequence[index]);
    }
    return transposedScale;
}