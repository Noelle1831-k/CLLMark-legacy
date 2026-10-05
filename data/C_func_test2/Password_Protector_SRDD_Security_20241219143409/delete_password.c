void delete_password(const char *site) {
    FILE *file = fopen("passwords.dat", "r");
    FILE *temp_file = fopen("temp.dat", "w");
    if (file == NULL || temp_file == NULL) {
        perror("Error opening files");
        exit(1);
    }
    char line[200], stored_site[100], stored_password[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%99[^:]:%99s", stored_site, stored_password);
        if (strcmp(stored_site, site) != 0) {
            fprintf(temp_file, "%s:%s\n", stored_site, stored_password);
        }
    }
    fclose(file);
    fclose(temp_file);
    remove("passwords.dat");
    rename("temp.dat", "passwords.dat");
}