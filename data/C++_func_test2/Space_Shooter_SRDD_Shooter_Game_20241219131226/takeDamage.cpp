void Spaceship::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << "Spaceship took " << damage << " damage, health is now " << health << "." << std::endl;
}