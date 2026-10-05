void addWord(const string& word, const string& definition) {
        for (int i = 0; i < flashcards.size(); ++i) {
            if (flashcards[i].getWord() == word) {
                cout << "This word is already in your vocabulary list.\n";
                return;
            }
        }
        Flashcard newCard(word, definition);
        flashcards.push_back(newCard);
        progressTracker.updateProgress(flashcards.size());
    }