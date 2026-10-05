void Spaceship::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) {
        cout << "Spaceship destroyed!" << endl;
    }
}