Vendor* create_vendor(char *name, char *type, double price, char *location) {
    Vendor *vendor = (Vendor*)malloc(sizeof(Vendor));
    vendor->name = (char*)malloc(50 * sizeof(char));
    vendor->type = (char*)malloc(50 * sizeof(char));
    vendor->price = price;
    vendor->location = (char*)malloc(50 * sizeof(char));
    strcpy(vendor->name, name);
    strcpy(vendor->type, type);
    strcpy(vendor->location, location);
    return vendor;
}