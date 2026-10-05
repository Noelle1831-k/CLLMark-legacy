void Player::aimAndShoot() {
    if (rifles.empty()) {
        cout << "No rifles available!" << endl;
        return;
    }
    cout << "Aiming and shooting with " << rifles[0].getName() << "..." << endl;
    score += 10;
}