void VocabularyGame::pictureLabeling(vector<string> &vocabulary, int difficulty, ProgressTracker &progress) {
    cout << "Playing picture labeling at difficulty " << difficulty << endl;
    int n = vocabulary.size();
    for (int i = 0; i < n; i++) {
        cout << "Label the picture for: " << vocabulary[i] << endl; 
        string userLabel;
        cout << "Enter your label for this picture: ";
        cin >> userLabel;
        if (rand() % 2 == 0) {
            cout << "Correct label!" << endl;
            progress.updateScore(15);
        } else {
            cout << "Incorrect label. Try again!" << endl;
        }
    }
}