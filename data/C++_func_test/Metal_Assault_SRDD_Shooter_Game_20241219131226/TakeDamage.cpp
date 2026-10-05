void Enemy::TakeDamage(int amount) {
    health -= amount;
    cout << "Enemy taking damage: " << amount << ", Health: " << health << endl;
    if (health <= 0) {
        cout << "Enemy is dead!" << endl;
    }
}