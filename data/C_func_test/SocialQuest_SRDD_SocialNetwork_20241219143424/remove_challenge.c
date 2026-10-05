void remove_challenge(ScavengerHunt *hunt, int index) {
    if (index < 0 || index >= hunt->num_challenges) return;
    free(hunt->challenges[index]);
    for (int i = index; i < hunt->num_challenges - 1; i++) {
        hunt->challenges[i] = hunt->challenges[i + 1];
    }
    hunt->num_challenges--;
    hunt->challenges = (Challenge**)realloc(hunt->challenges, sizeof(Challenge*) * hunt->num_challenges);
}