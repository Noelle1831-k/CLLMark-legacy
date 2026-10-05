void findMatches() {
    if (userCount < 2) {
        printf("Not enough profiles to find matches.\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        printf("\nMatches for %s:\n", userDatabase[i].name);
        for (int j = 0; j < userCount; j++) {
            if (i == j) continue;
            int commonInterests = 0;
            for (int k = 0; k < userDatabase[i].interestCount; k++) {
                for (int l = 0; l < userDatabase[j].interestCount; l++) {
                    if (strcmp(userDatabase[i].interests[k], userDatabase[j].interests[l]) == 0) {
                        commonInterests++;
                    }
                }
            }
            if (commonInterests > 0) {
                printf("  %s (Common Interests: %d)\n", userDatabase[j].name, commonInterests);
            }
        }
    }
}