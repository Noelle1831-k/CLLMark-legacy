void loadProfile(UserProfile *profile) {
    strcpy(profile->username, "default_user");
    profile->difficultyLevel = 1;
    printf("Profile loaded for user: %s\n", profile->username);
}