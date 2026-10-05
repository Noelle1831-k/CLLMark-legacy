void ConnectHive::viewMarketplace() {
    if (marketplaceItems.empty()) {
        cout << "No items in marketplace.\n";
        return;
    }
    for (const auto& item : marketplaceItems) {
        item.viewItem();
    }
}