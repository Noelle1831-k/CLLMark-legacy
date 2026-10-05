void move_tank(Tank *tank, float x, float y) {
    printf("Moving tank %s to new position (%.2f, %.2f)\n", tank->type, x, y);
    tank->position[0] = x;
    tank->position[1] = y;
}