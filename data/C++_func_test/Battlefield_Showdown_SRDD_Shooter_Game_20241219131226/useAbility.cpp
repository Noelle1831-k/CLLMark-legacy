void Player::useAbility(Ability& ability) {
    cout << name << " uses ability: " << ability.getName() << endl;
    ability.activate();
}