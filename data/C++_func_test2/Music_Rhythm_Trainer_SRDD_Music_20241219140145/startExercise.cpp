void RhythmExercise::startExercise() {
    pattern.generatePattern(difficulty);
    pattern.displayPattern();
    cout << "Clap along with the pattern!" << endl;
    evaluatePerformance();
}