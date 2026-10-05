void Vendor::listVendors() const {
    printf("Vendors List:\n");
    for (const auto &vendor : vendors) {
        cout << "- " << vendor << endl;
    }
}