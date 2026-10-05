void Shot::simulateShot() {
    speed = rand() % 100 + 50;
    angle = rand() % 360;
    cout << "Shot simulated with speed: " << speed << " and angle: " << angle << endl;
}