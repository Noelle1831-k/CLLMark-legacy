int calculate_goalie_positioning(float shot_angle, float goalie_x, float goalie_y) {
    float distance = sqrt(pow(goalie_x - (100 - shot_angle), 2) + pow(goalie_y - shot_angle, 2));
    if (distance < 15) { 
        return 1; 
    }
    return 0; 
}