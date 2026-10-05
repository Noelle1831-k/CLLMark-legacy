void UserProfile::viewLearnedWords() const {
    if (learnedWords.empty()) {
        cout << "You haven't learned any words yet." << endl;
    } else {
        cout << "Learned Words:" << endl;
        for (size_t i = 0; i < learnedWords.size(); ++i) {
            cout << learnedWords[i] << endl;
        }
    }
}