void Player::train() {
    skillLevel = skillLevel + 5; 
    stamina = stamina - 10; 
    cout << name << " has trained! Skill: " << skillLevel << ", Stamina: " << stamina << endl;
}