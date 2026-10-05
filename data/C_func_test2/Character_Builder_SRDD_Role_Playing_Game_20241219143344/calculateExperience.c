void calculateExperience(Character *character, int experienceGained) {
    character->experience = character->experience + experienceGained;
    printf("Experience gained: %d\n", experienceGained);
}