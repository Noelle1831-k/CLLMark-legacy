void Target::move() {
    x += speed;
    y += speed;
    if (x > 100) x = 100;
    if (y > 100) y = 100;
    cout << "Target moved to (" << x << ", " << y << ")" << endl;
}