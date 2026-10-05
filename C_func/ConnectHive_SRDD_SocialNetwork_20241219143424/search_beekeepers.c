void search_beekeepers() {
    char keyword[50];
    printf("\nEnter a name or location to search: ");
    scanf(" %[^\n]", keyword); 
    UserProfile profiles[MAX_PROFILES];
    int count = load_all_profiles(profiles);
    printf("\n==== Search Results ====\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(profiles[i].name, keyword) || strstr(profiles[i].location, keyword)) {
            printf("Name: %s, Location: %s, Experience: %d years\n",
                   profiles[i].name, profiles[i].location, profiles[i].experience_years);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching profiles found.\n");
    }
    printf("========================\n");
}