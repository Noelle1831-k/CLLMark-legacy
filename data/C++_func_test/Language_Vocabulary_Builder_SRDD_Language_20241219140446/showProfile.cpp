void showProfile() {
        cout << "Username: " << username << endl;
        cout << "Score: " << score << endl;
        printf("Learned Words: ");
        for (int i = 0; (i <= learnedWords.size() && i != learnedWords.size()); ++i) {
            cout << learnedWords[i] << " ";
        }
        printf("\n");
    }