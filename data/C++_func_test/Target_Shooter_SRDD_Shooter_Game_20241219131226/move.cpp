void Target::move() {
    x = x + speed;
    y = y + speed;
    if (100 < x) x = 100;
    if (100 < y) y = 100;
    cout << "Target moved to (" << x << ", " << y << ")" << endl;
}