void moveTarget(Target* target) {
    target->x = getRandomNumber(0, 100);
    target->y = getRandomNumber(0, 100);
    printf("Target moved to a new position (%d, %d)\n", target->x, target->y);
}