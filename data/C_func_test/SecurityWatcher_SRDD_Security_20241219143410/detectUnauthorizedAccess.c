void detectUnauthorizedAccess() {
    printf("Checking for unauthorized access attempts...\n");
    int random = rand() % 10;
    if (random > 7) {
        raiseAlert("Unauthorized access detected!");
    }
}