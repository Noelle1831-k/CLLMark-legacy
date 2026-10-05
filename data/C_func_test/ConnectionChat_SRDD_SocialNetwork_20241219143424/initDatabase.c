void initDatabase() {
    FILE *file = fopen("users.db", "rb");
    if (file) {
        fread(&userCount, sizeof(int), 1, file);
        fread(users, sizeof(UserProfile), userCount, file);
        fclose(file);
        printf("Loaded %d user profiles from database.\n", userCount);
    } else {
        printf("No existing data found. Starting fresh.\n");
    }
}