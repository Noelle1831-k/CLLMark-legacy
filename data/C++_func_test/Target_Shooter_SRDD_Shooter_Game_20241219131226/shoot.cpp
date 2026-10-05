bool Player::shoot(Target &target) {
    int shotX, shotY;
    cout << "Enter your shot coordinates (x y): ";
    cin >> shotX >> shotY;
    cout << "Player shot at (" << shotX << ", " << shotY << ")" << endl;
    if (target.checkHit(shotX, shotY)) {
        score += 10; 
        return true;
    }
    cout << "Missed! Try again." << endl;
    return false;
}