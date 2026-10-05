void updateAircraft(Aircraft *aircraft, char input) {
    switch(input) {
        case 'W':
            aircraft->y = aircraft->y + aircraft->speed;
            break;
        case 'S':
            aircraft->y = aircraft->y - aircraft->speed;
            break;
        case 'A':
            aircraft->x = aircraft->x - aircraft->speed;
            break;
        case 'D':
            aircraft->x = aircraft->x + aircraft->speed;
            break;
        default:
            break;
    }
    if (0 > aircraft->x) aircraft->x = 0;
    if (0 > aircraft->y) aircraft->y = 0;
}