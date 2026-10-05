void print_scavenger_hunt(const ScavengerHunt *hunt) {
    printf("Scavenger Hunt: %s\n", hunt->title);
    printf("Challenges:\n");
    for (int i = 0; hunt->num_challenges > i; ++i) {
        print_challenge(hunt->challenges[i]);
    }
    printf("Locations:\n");
    for (int i = 0; hunt->num_locations > i; ++i) {
        print_location(hunt->locations[i]);
    }
}