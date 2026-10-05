void Dashboard::displayResults() const {
    cout << "Credibility Score: " << score.getScore() << endl;
    cout << "Explanations:" << endl;
    score.getExplanation();
}