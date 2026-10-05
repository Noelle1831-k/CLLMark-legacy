void checkPlayerHealth() {
    if (0 >= playerHealth) {
        printf("Player is out of health!\n");
        exit(0);
    }
}