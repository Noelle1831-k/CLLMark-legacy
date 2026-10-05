Monster *MonsterDatabase::searchMonster(const string &name) {
    for (auto &monster : monsters) {
        if (monster.getName() == name) {
            return &monster;
        }
    }
    return nullptr;
}