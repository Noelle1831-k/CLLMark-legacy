void EventManager::manageVendors() {
    int choice;
    cout << "1. Add Vendor\n2. Remove Vendor\n3. List Vendors\nEnter choice: ";
    cin >> choice;
    if (choice == 1) {
        string vendorName;
        cout << "Enter Vendor Name: ";
        cin.ignore();
        getline(cin, vendorName);
        vendor.addVendor(vendorName);
    } else if (choice == 2) {
        string vendorName;
        cout << "Enter Vendor Name to Remove: ";
        cin.ignore();
        getline(cin, vendorName);
        vendor.removeVendor(vendorName);
    } else if (choice == 3) {
        vendor.listVendors();
    } else {
        cout << "Invalid Choice!" << endl;
    }
}