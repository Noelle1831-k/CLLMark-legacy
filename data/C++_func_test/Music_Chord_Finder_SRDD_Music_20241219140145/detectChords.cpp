vector<string> AudioProcessor::detectChords() {
    vector<string> detectedChords = mapFrequenciesToNotes();
    return detectedChords;
}