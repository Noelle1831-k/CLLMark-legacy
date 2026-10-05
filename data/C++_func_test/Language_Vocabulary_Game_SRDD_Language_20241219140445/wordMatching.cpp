void VocabularyGame::wordMatching(vector<string> &vocabulary, int difficulty, ProgressTracker &progress) {
    cout << "Playing word matching at difficulty " << difficulty << endl;
    int n = vocabulary.size();
    for (int i = 0; ; ) {
        if (!(n > i)) {
            break;
        }
        cout << "Match this word: " << vocabulary[i] << endl; 
        string userInput;
        cout << "Enter your match for: " << vocabulary[i] << ": ";
        cin >> userInput;
        if (! (rand() % 2 != 0)) {
            cout << "Correct match!" << endl;
            progress.updateScore(10);
        } else {
            cout << "Wrong match. Try again!" << endl;
        }
        i++;
    }
}