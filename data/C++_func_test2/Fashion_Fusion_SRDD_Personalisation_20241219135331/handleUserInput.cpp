void FashionFusionApp::handleUserInput(int choice) {
    string item;
    switch (choice) {
        case 1:
            cout << "Enter item to add: ";
            cin.ignore(); 
            getline(cin, item);
            wardrobe.addItem(item);
            break;
        case 2:
            cout << "Enter item to remove: ";
            cin.ignore(); 
            getline(cin, item);
            wardrobe.removeItem(item);
            break;
        case 3:
            {
                vector<string> items = wardrobe.listItems();
                for (vector<string>::const_iterator it = items.begin(); it != items.end(); ++it) {
                    cout << *it << endl;
                }
            }
            break;
        case 4:
            outfit.createOutfit(wardrobe.listItems());
            break;
        case 5:
            outfit.displayOutfit();
            break;
        case 0:
            cout << "Exiting Fashion Fusion." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}