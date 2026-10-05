int main() {
    InventoryManager inventoryManager;
    OrderManager orderManager;
    ReportGenerator reportGenerator;
    int choice;
    do {
        displayMenu();
        choice = getValidatedChoice();
        switch (choice) {
            case 1: {
                string name;
                int quantity;
                double price;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price per unit: ";
                cin >> price;
                inventoryManager.addItem(name, quantity, price);
                break;
            }
            case 2: {
                string name;
                cout << "Enter item name to remove: ";
                cin >> name;
                inventoryManager.removeItem(name);
                break;
            }
            case 3: {
                string name;
                int quantity;
                double price;
                cout << "Enter item name to update: ";
                cin >> name;
                cout << "Enter new quantity: ";
                cin >> quantity;
                cout << "Enter new price: ";
                cin >> price;
                inventoryManager.updateItem(name, quantity, price);
                break;
            }
            case 4: {
                string name;
                cout << "Enter item name to search: ";
                cin >> name;
                inventoryManager.searchItem(name);
                break;
            }
            case 5:
                inventoryManager.displayAllItems();
                break;
            case 6: {
                string name;
                int quantity;
                cout << "Enter item name to order: ";
                cin >> name;
                cout << "Enter quantity: ";
                cin >> quantity;
                orderManager.placeOrder(name, quantity);
                break;
            }
            case 7: {
                string name;
                cout << "Enter item name to cancel order: ";
                cin >> name;
                orderManager.cancelOrder(name);
                break;
            }
            case 8:
                orderManager.displayOrders();
                break;
            case 9:
                reportGenerator.generateInventoryReport(inventoryManager);
                break;
            case 10:
                reportGenerator.generateOrderReport(orderManager);
                break;
            case 11:
                inventoryManager.sortItems();
                break;
            case 12:
                orderManager.sortOrders();
                break;
            case 13:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);
    return 0;
}