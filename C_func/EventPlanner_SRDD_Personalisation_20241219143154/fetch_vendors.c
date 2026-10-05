void fetch_vendors(Database *db, VendorRecommendation *recommendation) {
    db->vendor_count = 3;
    db->vendor_data = (Vendor*)malloc(db->vendor_count * sizeof(Vendor));
    db->vendor_data[0] = *create_vendor("Catering Co.", "caterer", 5000, "New York");
    db->vendor_data[1] = *create_vendor("Photo Magic", "photographer", 3000, "Los Angeles");
    db->vendor_data[2] = *create_vendor("Decor Delight", "decorator", 4000, "Chicago");
    recommendation->vendors = db->vendor_data;
    recommendation->vendor_count = db->vendor_count;
}