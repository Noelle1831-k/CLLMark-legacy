void searchCard(string cardName) const {
        cout << "Searching for card: " << cardName << endl;
        int found = 0;
        for (int i = 0; i < folders.size(); i++) {
            vector<Card> cards = folders[i].getCards();
            for (int j = 0; j < cards.size(); j++) {
                if (cards[j].getName() == cardName) {
                    cards[j].printDetails();
                    found = 1;
                }
            }
        }
        if (!found) {
            cout << "Card not found." << endl;
        }
    }