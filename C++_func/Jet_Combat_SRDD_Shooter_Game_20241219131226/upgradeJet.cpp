void Jet::upgradeJet(int speedBoost, int agilityBoost, int healthBoost) {
    speed += speedBoost;
    agility += agilityBoost;
    health += healthBoost;
    cout << name << " upgraded! New speed: " << speed << ", New agility: " << agility << ", New health: " << health << "." << endl;
}