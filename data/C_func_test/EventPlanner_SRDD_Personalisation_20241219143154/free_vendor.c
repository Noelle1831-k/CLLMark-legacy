void free_vendor(Vendor *vendor) {
    free(vendor->name);
    free(vendor->type);
    free(vendor->location);
    free(vendor);
}