void Inventory::showInventory() {
    cout << "Inventory list: \n";
    for (const auto &item : stock) {
        cout << item.first << ": " << item.second << " units available." << endl;
    }
}