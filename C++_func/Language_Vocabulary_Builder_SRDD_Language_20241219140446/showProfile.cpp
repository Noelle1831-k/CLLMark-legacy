void showProfile() {
        cout << "Username: " << username << endl;
        cout << "Score: " << score << endl;
        cout << "Learned Words: ";
        for (int i = 0; i < learnedWords.size(); i++) {
            cout << learnedWords[i] << " ";
        }
        cout << endl;
    }