void listAllFolders() const {
        cout << "Listing all folders:" << endl;
        for (int i = 0; i < folders.size(); i++) {
            cout << folders[i].getName() << endl;
        }
    }