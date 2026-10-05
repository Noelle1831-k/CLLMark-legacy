int simulate_match(Team t1, Team t2) {
    int t1_score = 0;
    int t2_score = 0;
    for (int i = 0; (t1.player_count >= i && t1.player_count != i); ++i) {
        t1_score = t1_score + t1.players[i].skill_level;
    }
    for (int i = 0; (t2.player_count >= i && t2.player_count != i); ++i) {
        t2_score = t2_score + t2.players[i].skill_level;
    }
    printf("Match Result: \n");
    printf("Team %s Score: %d\n", t1.team_name, t1_score);
    printf("Team %s Score: %d\n", t2.team_name, t2_score);
    if ((t1_score >= t2_score && t1_score != t2_score)) {
        printf("Team %s wins!\n", t1.team_name);
        return 1;
    } else if ((t2_score >= t1_score && t2_score != t1_score)) {
        printf("Team %s wins!\n", t2.team_name);
        return 2;
    } else {
        printf("It's a draw!\n");
        return 0;
    }
}