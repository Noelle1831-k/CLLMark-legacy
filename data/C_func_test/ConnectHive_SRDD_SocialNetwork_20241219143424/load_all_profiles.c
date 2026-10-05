int load_all_profiles(UserProfile profiles[]) {
    FILE *file = fopen("profiles.dat", "rb");
    if (!file) return 0;
    int count = 0;
    while (fread(&profiles[count], sizeof(UserProfile), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}