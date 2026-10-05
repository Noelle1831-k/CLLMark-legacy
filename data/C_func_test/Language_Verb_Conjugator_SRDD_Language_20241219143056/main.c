int main() {
    VerbDatabase db;
    db.num_verbs = 0;
    load_database_from_file(&db, DATABASE_FILE);
    main_menu(&db);
    save_database_to_file(&db, DATABASE_FILE);
    return 0;
}