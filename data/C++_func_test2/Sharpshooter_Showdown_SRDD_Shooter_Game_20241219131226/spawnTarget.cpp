void Target::spawnTarget() {
    x = rand() % 100;
    y = rand() % 100;
    cout << "Target spawned at (" << x << ", " << y << ")" << endl;
}