void MonsterDatabase::updateMonster(const string &name, int health,
                                     int attack, vector<string> abilities,
                                     vector<string> weaknesses,
                                     string reward) {
    for (auto &monster : monsters) {
        if (monster.getName() == name) {
            monster.updateStats(health, attack, abilities, weaknesses, reward);
            return;
        }
    }
}