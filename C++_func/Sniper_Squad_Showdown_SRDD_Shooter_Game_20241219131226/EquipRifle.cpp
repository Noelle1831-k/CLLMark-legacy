void Player::EquipRifle(SniperRifle& rifle) {
    equippedRifle = rifle;
    cout << "Equipped " << rifle.GetDetails() << ".\n";
}