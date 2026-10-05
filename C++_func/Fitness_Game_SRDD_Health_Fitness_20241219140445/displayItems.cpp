void displayItems() {
        cout << "Shop Items: \n";
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].name << " (Price: " << items[i].price << " coins)\n";
        }
    }