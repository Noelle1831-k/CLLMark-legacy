void handle_player_controls() {
    char input;
    printf("Enter control (w: accelerate, s: brake, a: left, d: right): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            player.speed += player.acceleration;
            break;
        case 's':
            player.speed -= player.acceleration;
            if (player.speed < 0) player.speed = 0;
            break;
        case 'a':
            player.position -= player.turning_speed;
            break;
        case 'd':
            player.position += player.turning_speed;
            break;
        default:
            printf("Invalid input.\n");
    }
    update_player_position();
}