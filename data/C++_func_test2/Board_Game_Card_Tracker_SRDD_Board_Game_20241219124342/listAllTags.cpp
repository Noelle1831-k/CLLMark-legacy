void listAllTags() const {
        cout << "Listing all tags:" << endl;
        for (int i = 0; i < tags.size(); i++) {
            cout << tags[i].getName() << endl;
        }
    }