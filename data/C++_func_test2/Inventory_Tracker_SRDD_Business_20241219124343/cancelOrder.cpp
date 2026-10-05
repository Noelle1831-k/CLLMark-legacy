void OrderManager::cancelOrder(string name) {
    for (auto it = orderList.begin(); it != orderList.end(); ++it) {
        if (it->first == name) {
            orderList.erase(it);
            cout << "Order canceled successfully.\n";
            return;
        }
    }
    cout << "Order not found.\n";
}