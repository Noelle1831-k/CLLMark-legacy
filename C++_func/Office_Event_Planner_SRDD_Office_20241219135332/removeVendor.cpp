void Vendor::removeVendor(const string &vendorName) {
    auto it = find(vendors.begin(), vendors.end(), vendorName);
    if (it != vendors.end()) {
        vendors.erase(it);
        cout << "Vendor removed: " << vendorName << endl;
    } else {
        cout << "Vendor not found: " << vendorName << endl;
    }
}