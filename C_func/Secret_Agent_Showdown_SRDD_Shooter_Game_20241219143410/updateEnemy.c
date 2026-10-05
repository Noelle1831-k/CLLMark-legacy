void updateEnemy(Enemy *enemy, Player *player) {
    if (isPlayerVisible(enemy, player)) {
        chasePlayer(enemy, player);
    } else {
        patrolArea(enemy);
    }
}