Database* create_database() {
    Database *db = (Database*)malloc(sizeof(Database));
    db->vendor_data = NULL;
    db->vendor_count = 0;
    return db;
}