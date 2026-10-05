void train_player(Player *p) {
    p->skill_level += rand() % 10;
    p->experience += rand() % 5;
    p->stamina += rand() % 3;
    if (p->stamina > 100) p->stamina = 100;
    if (p->skill_level > 100) p->skill_level = 100;
    if (p->experience > 100) p->experience = 100;
    printf("Training completed. Player stats updated!\n");
}