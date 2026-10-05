void displayInventory() {
        cout << "Your Inventory: ";
        for (int i = 0; i < inventory.size(); i++) {
            cout << inventory[i] << " ";
        }
        cout << endl;
    }