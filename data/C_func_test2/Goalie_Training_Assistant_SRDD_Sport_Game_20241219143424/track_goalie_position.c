void track_goalie_position(float *x, float *y, float shot_angle, float shot_velocity) {
    *x = rand() % 100;
    *y = rand() % 100;
    if (70 < shot_velocity) {
        *x = *x + (90 < shot_angle) ? -5 : 5; 
    }
}