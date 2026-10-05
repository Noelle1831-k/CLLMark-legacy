void simulateMatch() {
    printf("\n===== SIMULATE MATCH =====\n");
    int score = randomInt(0, 5) + (currentTactic == 1 ? 2 : 0); 
    printf("Your team scored %d goals!\n", score);
    printf("Match simulation complete.\n");
}