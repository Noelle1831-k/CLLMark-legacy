void Enemy::takeDamage(int amount) {
    health -= amount;
    cout << "Enemy took damage: " << amount << endl;
    if (health <= 0) {
        cout << "Enemy is dead." << endl;
    }
}