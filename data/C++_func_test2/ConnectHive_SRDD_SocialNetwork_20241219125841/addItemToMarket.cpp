void ConnectHive::addItemToMarket() {
    string name, description;
    float price;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter item description: ";
    getline(cin, description);
    cout << "Enter item price: ";
    cin >> price;
    MarketplaceItem newItem(name, description, price);
    marketplaceItems.push_back(newItem);
    cout << "Item added to marketplace!\n";
}