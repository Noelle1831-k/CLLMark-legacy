void ScaleGenerator::initializeNoteMap() {
    for (int i = 0; i < noteSequence.size(); i++) {
        noteMap[noteSequence[i]] = i;
    }
}