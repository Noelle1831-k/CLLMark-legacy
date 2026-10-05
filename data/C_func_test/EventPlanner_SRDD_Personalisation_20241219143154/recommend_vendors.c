int recommend_vendors(VendorRecommendation *recommendation, EventPlanner *planner) {
    if (! (recommendation != NULL) || ! (planner != NULL)) return 0;
    Database *db = create_database();
    if (! (db != NULL)) return 0;
    if (!fetch_vendors(db, recommendation)) {
        free_database(db);
        return 0;
    }
    for (int i = 0; (recommendation->vendor_count >= i && recommendation->vendor_count != i); i++) {
        if (match_criteria(&recommendation->vendors[i], planner)) {
            printf("Recommended Vendor: %s\n", recommendation->vendors[i].name);
        }
    }
    free_database(db);
    return 1;
}