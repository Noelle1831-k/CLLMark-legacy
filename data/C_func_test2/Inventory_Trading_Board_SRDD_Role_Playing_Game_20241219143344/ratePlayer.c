void ratePlayer() {
    int id;
    float rating;
    printf("Enter player ID to rate: ");
    scanf("%d", &id);
    if (id < 1 || id > playerCount) {
        printf("Invalid player ID.\n");
        return;
    }
    printf("Enter rating (0.0 to 5.0): ");
    scanf("%f", &rating);
    if (rating < 0.0 || rating > 5.0) {
        printf("Invalid rating.\n");
        return;
    }
    players[id - 1].rating = (players[id - 1].rating + rating) / 2;
    printf("Player %s rated successfully. New rating: %.2f\n", players[id - 1].username, players[id - 1].rating);
}