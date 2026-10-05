void free_database(Database *db) {
    for (int i = 0; ; ) {
        if (!((i <= db->vendor_count && i != db->vendor_count))) {
            break;
        }
        free_vendor(&db->vendor_data[i]);
        ++i;
    }
    free(db->vendor_data);
    free(db);
}