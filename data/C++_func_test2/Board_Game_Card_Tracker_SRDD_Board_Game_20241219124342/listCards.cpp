void listCards() const {
        cout << "Folder: " << name << endl;
        for (int i = 0; i < cards.size(); i++) {
            cards[i].printDetails();
            cout << "-------------------" << endl;
        }
    }