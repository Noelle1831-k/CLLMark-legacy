void updateGame() {
    moveTarget(&target);
    int x, y;
    printf("Target is moving...\n");
    printf("Enter coordinates to shoot (x y): ");
    scanf("%d %d", &x, &y);
    shoot(&player, &target, x, y);
    printf("Current Score: %d\n\n", getScore(&player));
}