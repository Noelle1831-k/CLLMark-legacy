void Business::displayStatus() {
    cout << "Business Name: " << name << endl;
    cout << "Revenue: $" << revenue << endl;
    cout << "Expenses: $" << expenses << endl;
    employeeManager.displayEmployees();
    inventoryManager.displayInventory();
    financeManager.displayFinancials();
    marketingManager.displayCampaigns();
}