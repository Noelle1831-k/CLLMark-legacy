void Jet::upgradeJet(int speedBoost, int agilityBoost, int healthBoost) {
    speed = speed + speedBoost;
    agility = agility + agilityBoost;
    health = health + healthBoost;
    cout << name << " upgraded! New speed: " << speed << ", New agility: " << agility << ", New health: " << health << "." << endl;
}