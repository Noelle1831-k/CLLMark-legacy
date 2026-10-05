void Vendor::listVendors() const {
    cout << "Vendors List:" << endl;
    for (const auto &vendor : vendors) {
        cout << "- " << vendor << endl;
    }
}