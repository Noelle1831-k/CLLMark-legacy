void add_challenge(ScavengerHunt *hunt, Challenge *challenge) {
    hunt->challenges = (Challenge**)realloc(hunt->challenges, sizeof(Challenge*) * (hunt->num_challenges + 1));
    hunt->challenges[hunt->num_challenges] = challenge;
    hunt->num_challenges++;
}