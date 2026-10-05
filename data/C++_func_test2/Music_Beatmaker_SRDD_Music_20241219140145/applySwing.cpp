void BeatMaker::applySwing() {
    cout << "Applying swing..." << endl;
    swing = Utility::calculateSwing(tempo);
    cout << "Swing applied: " << swing << endl;
}