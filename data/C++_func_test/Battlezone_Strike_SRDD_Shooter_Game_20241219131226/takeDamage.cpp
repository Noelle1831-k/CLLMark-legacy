void Tank::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        cout << type << " destroyed!" << endl;
    } else {
        cout << type << " took " << damage << " damage, remaining health: " << health << endl;
    }
}