void Battle::executeTurn(Team& team1, Team& team2) {
    Character* attacker = team1.getNextAliveCharacter();
    Character* defender = team2.getNextAliveCharacter();
    if (attacker && defender) {
        attacker->attack(*defender);
        if (!defender->isAlive()) {
            team2.removeCharacter(defender);
        } else {
            defender->useAbility(*attacker);
        }
    }
    swap(team1, team2); 
}