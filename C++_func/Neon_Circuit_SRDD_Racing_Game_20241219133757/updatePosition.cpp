void Vehicle::updatePosition() {
    x += speed * cos(direction * M_PI / 180);
    y += speed * sin(direction * M_PI / 180);
}