void check_collisions() {
    printf("Checking for collisions...\n");
    if (player.position < 0 || player.position > track.length) {
        printf("Collision detected! Player went off track.\n");
        player.speed = 0; 
    }
}