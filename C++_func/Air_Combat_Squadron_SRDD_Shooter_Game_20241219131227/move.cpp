void Enemy::move() {
    x += rand() % 3 - 1; 
    y += rand() % 3 - 1;
}