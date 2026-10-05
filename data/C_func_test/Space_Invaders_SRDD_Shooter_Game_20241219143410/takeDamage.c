void takeDamage(Alien *alien, int damage) {
    alien->health -= damage;
    if (alien->health <= 0) {
        alien->isAlive = 0;
    }
}