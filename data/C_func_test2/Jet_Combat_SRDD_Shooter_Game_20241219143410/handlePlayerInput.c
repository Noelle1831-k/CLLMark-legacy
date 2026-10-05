void handlePlayerInput() {
    char input;
    printf("Enter Command (W/A/S/D to move, F to fire): ");
    scanf(" %c", &input);
    switch (input) {
        case 'W': case 'w': player.y = player.y - player.speed; break;
        case 'A': case 'a': player.x = player.x - player.speed; break;
        case 'S': case 's': player.y = player.y + player.speed; break;
        case 'D': case 'd': player.x = player.x + player.speed; break;
        case 'F': case 'f': fireWeapon(); break;
        default: printf("Invalid Command!\n");
    }
}