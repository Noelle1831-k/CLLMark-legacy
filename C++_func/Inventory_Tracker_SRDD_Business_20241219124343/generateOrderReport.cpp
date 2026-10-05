void ReportGenerator::generateOrderReport(const OrderManager &orderManager) const {
    cout << "\n===== Order Report =====\n";
    orderManager.displayOrders();
}