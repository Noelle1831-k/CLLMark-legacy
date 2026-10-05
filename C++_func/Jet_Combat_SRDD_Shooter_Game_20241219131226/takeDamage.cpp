void Jet::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        cout << name << " has been destroyed!" << endl;
    } else {
        cout << name << " took " << damage << " damage. Remaining health: " << health << "." << endl;
    }
}