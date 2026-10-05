void OrderManager::placeOrder(string name, int quantity) {
    orderList.push_back(make_pair(name, quantity));
    cout << "Order placed successfully.\n";
}