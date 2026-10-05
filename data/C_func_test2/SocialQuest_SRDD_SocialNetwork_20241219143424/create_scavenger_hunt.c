ScavengerHunt* create_scavenger_hunt(const char *title) {
    ScavengerHunt *hunt = (ScavengerHunt*)malloc(sizeof(ScavengerHunt));
    hunt->title = strdup(title);
    hunt->challenges = NULL;
    hunt->num_challenges = 0;
    hunt->locations = NULL;
    hunt->num_locations = 0;
    return hunt;
}