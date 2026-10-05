void Pet::battle(Pet& opponent) {
    int damage = rand() % 10 + 1;
    opponent.health -= damage;
    cout << name << " battles " << opponent.getName() << " causing " << damage << " damage." << endl;
}