int calculate_shipping_cost(int n, int parcels[][4]) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int x = parcels[i][0];
        int y = parcels[i][1];
        int h = parcels[i][2];
        int w = parcels[i][3];
        int size = x + y + h;
        int cost = 0;
        if (size <= 60 && w <= 2) cost = 600;
        else if (size <= 80 && w <= 5) cost = 800;
        else if (size <= 100 && w <= 10) cost = 1000;
        else if (size <= 120 && w <= 15) cost = 1200;
        else if (size <= 140 && w <= 20) cost = 1400;
        else if (size <= 160 && w <= 25) cost = 1600;
        total_cost += cost;
    }
    return total_cost;
}