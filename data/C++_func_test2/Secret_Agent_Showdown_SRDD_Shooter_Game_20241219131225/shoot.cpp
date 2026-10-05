void Player::shoot(std::vector<Enemy>& enemies) {
    for (int i = 0; i < enemies.size(); i++) {
        if (abs(enemies[i].getX() - x) <= 1 && abs(enemies[i].getY() - y) <= 1) {
            cout << "Enemy hit!" << endl;
            enemies[i].takeDamage(50);  
            return;
        }
    }
    cout << "Missed!" << endl;
}