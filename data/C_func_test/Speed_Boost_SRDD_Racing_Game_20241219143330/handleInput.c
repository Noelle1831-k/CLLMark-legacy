void handleInput() {
    printf("Handling input...\n");
    getInput();
    if (speedBoostAvailable) {
        applySpeedBoost();
    }
}