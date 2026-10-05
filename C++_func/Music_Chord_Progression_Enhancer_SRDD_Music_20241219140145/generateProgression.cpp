string ProgressionGenerator::generateProgression(const vector<string> &chords) {
    string result;
    for (vector<string>::const_iterator it = chords.begin(); it != chords.end(); ++it) {
        result += *it + " ";
    }
    return result;
}