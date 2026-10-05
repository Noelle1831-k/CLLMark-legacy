void move_player(int direction) {
    printf("Moving player in direction: %d\n", direction);
    if (direction == 0) player.y -= 1;  
    else if (direction == 1) player.x += 1;  
    else if (direction == 2) player.y += 1;  
    else if (direction == 3) player.x -= 1;  
    printf("Player moved to position (%d, %d).\n", player.x, player.y);
}