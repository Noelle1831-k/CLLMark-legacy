void Character::attack(Character& target) {
    cout << name << " attacks " << target.getName() << "!" << endl;
    target.takeDamage(attackPower);
}