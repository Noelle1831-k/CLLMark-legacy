void OrderManager::displayOrders() const {
    cout << left << setw(20) << "Item Name"
         << setw(10) << "Quantity" << endl;
    for (const auto &order : orderList) {
        cout << left << setw(20) << order.first
             << setw(10) << order.second << endl;
    }
}