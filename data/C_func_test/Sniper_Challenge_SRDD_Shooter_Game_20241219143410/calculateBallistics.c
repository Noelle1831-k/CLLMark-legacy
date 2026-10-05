void calculateBallistics(float angle, float velocity) {
    printf("Calculating ballistics...\n");
    float gravity = 9.8, time = (2 * velocity * sin(angle)) / gravity, range = velocity * cos(angle) * time;


    printf("Bullet range: %.2f meters\n", range);
}