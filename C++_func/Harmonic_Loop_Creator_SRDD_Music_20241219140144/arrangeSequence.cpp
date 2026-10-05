void HarmonicLoopCreator::arrangeSequence() {
    sort(sequence.begin(), sequence.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });
}