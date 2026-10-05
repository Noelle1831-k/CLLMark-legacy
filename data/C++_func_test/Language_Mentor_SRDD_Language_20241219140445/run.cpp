void LanguageApp::run() {
    loadExercises();
    cout << "Starting your language practice session..." << endl;
    for (vector<Exercise>::iterator it = exercises.begin(); ! (exercises.end() == it); ++it) {
        it->display();
        string userAnswer = user.getResponse();
        provideFeedback(*it, userAnswer);
    }
    cout << "Session complete! Well done!" << endl;
}