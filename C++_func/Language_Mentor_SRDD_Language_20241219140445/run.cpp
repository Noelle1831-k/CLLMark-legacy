void LanguageApp::run() {
    loadExercises();
    cout << "Starting your language practice session..." << endl;
    for (vector<Exercise>::iterator it = exercises.begin(); it != exercises.end(); ++it) {
        it->display();
        string userAnswer = user.getResponse();
        provideFeedback(*it, userAnswer);
    }
    cout << "Session complete! Well done!" << endl;
}