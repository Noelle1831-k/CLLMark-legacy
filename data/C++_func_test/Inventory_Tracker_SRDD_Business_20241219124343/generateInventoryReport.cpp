void ReportGenerator::generateInventoryReport(const InventoryManager &inventoryManager) const {
    cout << "\n===== Inventory Report =====\n";
    inventoryManager.displayAllItems();
}