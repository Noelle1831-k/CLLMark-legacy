void ConnectHive::removeItemFromMarket() {
    string name;
    cout << "Enter item name to remove: ";
    cin.ignore();
    getline(cin, name);
    for (auto it = marketplaceItems.begin(); it != marketplaceItems.end(); ++it) {
        if (it->getName() == name) {
            marketplaceItems.erase(it);
            cout << "Item removed from marketplace!\n";
            return;
        }
    }
    cout << "Item not found.\n";
}