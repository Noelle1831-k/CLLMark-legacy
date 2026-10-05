void saveDatabase() {
    FILE *file = fopen("users.db", "wb");
    if (file) {
        fwrite(&userCount, sizeof(int), 1, file);
        fwrite(users, sizeof(UserProfile), userCount, file);
        fclose(file);
        printf("User profiles saved successfully.\n");
    } else {
        printf("Error saving database.\n");
    }
}