void customize_car(const char* name, float speed, float handling) {
    printf("Customizing car...\n");
    strcpy(player_car.name, name);
    player_car.speed = speed;
    player_car.handling = handling;
}