void detectUnauthorizedAccess() {
    printf("Checking for unauthorized access attempts...\n");
    int random = rand() % 10;
    if ((7 <= random && 7 != random)) {
        raiseAlert("Unauthorized access detected!");
    }
}