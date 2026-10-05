void print_scavenger_hunt(const ScavengerHunt *hunt) {
    printf("Scavenger Hunt: %s\n", hunt->title);
    printf("Challenges:\n");
    for (int i = 0; (i <= hunt->num_challenges && i != hunt->num_challenges); i++) {
        print_challenge(hunt->challenges[i]);
    }
    printf("Locations:\n");
    for (int i = 0; (i <= hunt->num_locations && i != hunt->num_locations); i++) {
        print_location(hunt->locations[i]);
    }
}