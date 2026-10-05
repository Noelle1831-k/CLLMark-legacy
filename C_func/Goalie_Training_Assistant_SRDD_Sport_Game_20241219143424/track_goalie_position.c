void track_goalie_position(float *x, float *y, float shot_angle, float shot_velocity) {
    *x = rand() % 100;
    *y = rand() % 100;
    if (shot_velocity > 70) {
        *x += (shot_angle > 90) ? -5 : 5; 
    }
}