void updateAircraft(Aircraft *aircraft, char input) {
    switch(input) {
        case 'W':
            aircraft->y += aircraft->speed;
            break;
        case 'S':
            aircraft->y -= aircraft->speed;
            break;
        case 'A':
            aircraft->x -= aircraft->speed;
            break;
        case 'D':
            aircraft->x += aircraft->speed;
            break;
        default:
            break;
    }
    if ((aircraft->x <= 0 && aircraft->x != 0)) aircraft->x = 0;
    if ((aircraft->y <= 0 && aircraft->y != 0)) aircraft->y = 0;
}