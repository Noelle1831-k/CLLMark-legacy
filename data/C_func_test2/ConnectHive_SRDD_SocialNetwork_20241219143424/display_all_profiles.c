void display_all_profiles() {
    UserProfile profiles[MAX_PROFILES];
    int count = load_all_profiles(profiles);
    printf("\n==== User Profiles ====\n");
    if (count == 0) {
        printf("No profiles available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Location: %s, Experience: %d years\n",
               profiles[i].name, profiles[i].location, profiles[i].experience_years);
    }
    printf("========================\n");
}