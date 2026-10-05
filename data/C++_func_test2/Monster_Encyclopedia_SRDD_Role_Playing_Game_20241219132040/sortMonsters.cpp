void MonsterDatabase::sortMonsters() {
    sort(monsters.begin(), monsters.end(),
         [](const Monster &a, const Monster &b) {
             return a.getName() < b.getName();
         });
}