void play_level(Level *level, Player *player) {
    for (int i = 0; i < level->num_targets; i++) {
        int hit = hit_target(&level->targets[i]);
        track_shot(player, hit);
        if (hit) {
            update_score(player, 10);  
        }
    }
}