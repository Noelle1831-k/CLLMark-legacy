void Target::moveTarget() {
    x += rand() % 10 - 5;
    y += rand() % 10 - 5;
    cout << "Target moved to (" << x << ", " << y << ")" << endl;
}