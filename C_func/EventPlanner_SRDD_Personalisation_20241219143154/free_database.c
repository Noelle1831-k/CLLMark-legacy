void free_database(Database *db) {
    for (int i = 0; i < db->vendor_count; i++) {
        free_vendor(&db->vendor_data[i]);
    }
    free(db->vendor_data);
    free(db);
}