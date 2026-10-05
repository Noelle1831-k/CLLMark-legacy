void getAssociatedCards() const {
        cout << "Tag: " << name << endl;
        for (int i = 0; i < associatedCards.size(); i++) {
            associatedCards[i].printDetails();
            cout << "-------------------" << endl;
        }
    }