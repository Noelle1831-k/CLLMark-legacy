void Monster::updateStats(int newHealth, int newAttack,
                          vector<string> newAbilities,
                          vector<string> newWeaknesses, string newReward) {
    health = newHealth;
    attack = newAttack;
    abilities = newAbilities;
    weaknesses = newWeaknesses;
    reward = newReward;
}