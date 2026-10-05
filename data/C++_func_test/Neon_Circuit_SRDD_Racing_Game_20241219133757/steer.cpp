void Vehicle::steer(float angle) {
    direction += angle;
    if (direction > 360) direction -= 360;
    if (direction < 0) direction += 360;
}