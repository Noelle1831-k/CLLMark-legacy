void VocabularyGame::wordAssociation(vector<string> &vocabulary, int difficulty, ProgressTracker &progress) {
    cout << "Playing word association at difficulty " << difficulty << endl;
    int n = vocabulary.size();
    for (int i = 0; i < n; i++) {
        cout << "Associate a word with: " << vocabulary[i] << endl; 
        string userAssociation;
        cout << "Enter your association: ";
        cin >> userAssociation;
        if (rand() % 2 == 0) {
            cout << "Correct association!" << endl;
            progress.updateScore(20);
        } else {
            cout << "Wrong association. Try again!" << endl;
        }
    }
}