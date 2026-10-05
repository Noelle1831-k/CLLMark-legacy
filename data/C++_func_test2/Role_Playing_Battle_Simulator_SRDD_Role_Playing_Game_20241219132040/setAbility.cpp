void Character::setAbility(std::unique_ptr<Ability> newAbility) {
    ability = std::move(newAbility);
}