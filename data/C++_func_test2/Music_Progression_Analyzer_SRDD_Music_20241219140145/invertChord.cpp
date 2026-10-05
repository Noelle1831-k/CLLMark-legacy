vector<string> Utils::invertChord(string chord) {
    vector<string> invertedChords;
    if (chord == "C") {
        invertedChords.push_back("C/E");
        invertedChords.push_back("C/G");
    } else if (chord == "G") {
        invertedChords.push_back("G/B");
        invertedChords.push_back("G/D");
    } else {
        invertedChords.push_back(chord);
    }
    return invertedChords;
}