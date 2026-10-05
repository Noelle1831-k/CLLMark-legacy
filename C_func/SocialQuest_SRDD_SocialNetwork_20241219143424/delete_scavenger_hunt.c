void delete_scavenger_hunt(ScavengerHunt *hunt) {
    free(hunt->title);
    for (int i = 0; i < hunt->num_challenges; i++) {
        free(hunt->challenges[i]);
    }
    free(hunt->challenges);
    for (int i = 0; i < hunt->num_locations; i++) {
        free(hunt->locations[i]);
    }
    free(hunt->locations);
    free(hunt);
}