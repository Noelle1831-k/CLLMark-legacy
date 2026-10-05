int get_toll_fee(int depart, int depart_hour, int depart_min, int arrive, int arrive_hour, int arrive_min) {
    int tolls[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 300, 500, 750, 1800, 1950},
        {0, 300, 0, 200, 450, 1500, 1780},
        {0, 500, 200, 0, 250, 1300, 1600},
        {0, 750, 450, 250, 0, 1100, 1420},
        {0, 1800, 1500, 1300, 1100, 0, 300},
        {0, 1950, 1780, 1600, 1420, 300, 0}
    };
    int distances[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 17, 30, 45, 58},
        {0, 8, 0, 12, 21, 37, 50},
        {0, 17, 12, 0, 9, 25, 38},
        {0, 30, 21, 9, 0, 16, 29},
        {0, 45, 37, 25, 16, 0, 13},
        {0, 58, 50, 38, 29, 13, 0}
    };
    int start_minutes = depart_hour * 60 + depart_min;
    int end_minutes = arrive_hour * 60 + arrive_min;
    int fee = tolls[depart - 1][arrive - 1];
    int distance = distances[depart - 1][arrive - 1];
    if ((start_minutes >= 1050 && start_minutes <= 1170) || (end_minutes >= 1050 && end_minutes <= 1170)) {
        if (distance <= 40) {
            fee = ((fee + 25) / 50) * 25; 
        }
    }
    return fee;
}