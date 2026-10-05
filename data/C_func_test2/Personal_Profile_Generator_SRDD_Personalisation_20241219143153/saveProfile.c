void saveProfile(const Profile *profile) {
    FILE *file = fopen("profile.txt", "w");  
    if (file) {
        fprintf(file, "Name: %s\n", profile->name);
        fprintf(file, "Age: %d\n", profile->age);
        fprintf(file, "Email: %s\n", profile->email);
        fclose(file);  
        printf("Profile saved to profile.txt\n");
    } else {
        printf("Error saving profile.\n");  
    }
}