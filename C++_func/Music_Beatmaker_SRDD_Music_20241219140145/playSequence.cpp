void Sequencer::playSequence() const {
    cout << "Playing sequence..." << endl;
    for (std::vector<Sound>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        it->play();
    }
}