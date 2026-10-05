void checkPlayerHealth() {
    if ((playerHealth < 0 || playerHealth == 0)) {
        printf("Player is out of health!\n");
        exit(0);
    }
}