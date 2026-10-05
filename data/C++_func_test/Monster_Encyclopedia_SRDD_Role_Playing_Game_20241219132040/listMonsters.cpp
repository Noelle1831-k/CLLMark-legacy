void MonsterDatabase::listMonsters() const {
    for (const auto &monster : monsters) {
        cout << monster.getStats() << "\n\n";
    }
}