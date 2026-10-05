void handleCarInput(float* acceleration, float* braking) {
    if (keyPressed(KEY_UP)) {
        *acceleration = 1.0;
    } else {
        *acceleration = 0.0;
    }
    if (keyPressed(KEY_DOWN)) {
        *braking = 1.0;
    } else {
        *braking = 0.0;
    }
    if (keyPressed(KEY_LEFT)) {
        car.angle -= car.handling * 0.02;
    } else if (keyPressed(KEY_RIGHT)) {
        car.angle += car.handling * 0.02;
    }
}