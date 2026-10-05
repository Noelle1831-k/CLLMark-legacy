int main() {
    CollectionManager manager;
    int choice;
    do {
        cout << "\nCard Collection Manager Menu:" << endl;
        cout << "1. Add Folder" << endl;
        cout << "2. Add Tag" << endl;
        cout << "3. Add Card to Folder" << endl;
        cout << "4. Search Card" << endl;
        cout << "5. List Folders" << endl;
        cout << "6. List Tags" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string folderName;
            cout << "Enter folder name: ";
            cin.ignore();
            getline(cin, folderName);
            manager.addFolder(Folder(folderName));
        } else if (choice == 2) {
            string tagName;
            cout << "Enter tag name: ";
            cin.ignore();
            getline(cin, tagName);
            manager.addTag(Tag(tagName));
        } else if (choice == 3) {
            string folderName, cardName, condition;
            int quantity;
            cout << "Enter folder name: ";
            cin.ignore();
            getline(cin, folderName);
            cout << "Enter card name: ";
            getline(cin, cardName);
            cout << "Enter card condition: ";
            getline(cin, condition);
            cout << "Enter card quantity: ";
            cin >> quantity;
            manager.addCardToFolder(folderName, Card(cardName, quantity, condition));
        } else if (choice == 4) {
            string cardName;
            cout << "Enter card name: ";
            cin.ignore();
            getline(cin, cardName);
            manager.searchCard(cardName);
        } else if (choice == 5) {
            manager.listAllFolders();
        } else if (choice == 6) {
            manager.listAllTags();
        }
    } while (choice != 7);
    cout << "Exiting Card Collection Manager. Goodbye!" << endl;
    return 0;
}