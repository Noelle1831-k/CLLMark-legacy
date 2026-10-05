int hit_target(Target *target) {
    if (target->type == 1) {
        printf("Hit a moving target!\n");
    } else {
        printf("Hit a static target!\n");
    }
    target->is_hit = 1;
    return target->is_hit;
}