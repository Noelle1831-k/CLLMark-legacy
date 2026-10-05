void create_player() {
    printf("Creating player...\n");
    player.position = 0.0;
    player.speed = 0.0;
    player.car_id = 1; 
    player.acceleration = 0.05; 
    player.turning_speed = 2.0; 
    printf("Player created with default car.\n");
}