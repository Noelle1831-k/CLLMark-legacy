void Player::Shoot() {
    if (ammo > 0) {
        cout << "Player shooting..." << endl;
        ammo--;
    } else {
        cout << "Out of ammo!" << endl;
    }
}