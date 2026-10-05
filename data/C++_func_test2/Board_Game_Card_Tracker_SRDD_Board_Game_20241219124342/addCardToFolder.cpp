void addCardToFolder(const string& folderName, const Card& card) {
        int found = 0;
        for (int i = 0; i < folders.size(); i++) {
            if (folders[i].getName() == folderName) {
                folders[i].addCard(card);
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Folder not found: " << folderName << endl;
        }
    }