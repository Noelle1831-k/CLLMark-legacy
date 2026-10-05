bool Mission::CompleteMission(Player& player) {
    if (player.GetHealth() > difficulty) {
        player.TakeDamage(difficulty / 2);
        return true;
    } else {
        player.TakeDamage(difficulty);
        return false;
    }
}