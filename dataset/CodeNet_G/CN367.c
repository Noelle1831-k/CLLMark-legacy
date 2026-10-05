int max_num_customers(int n, int times[][6]) {
    int max_customers = 0;
    int i, j, k, l, m, o;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                int b_s = times[i][0], b_e = times[i][1];
                int l_s = times[j][2], l_e = times[j][3];
                int s_s = times[k][4], s_e = times[k][5];
                int served_customers = 0;
                for (l = 0; l < n; l++) {
                    if (b_s <= times[l][0] && b_e >= times[l][1] &&
                        l_s <= times[l][2] && l_e >= times[l][3] &&
                        s_s <= times[l][4] && s_e >= times[l][5]) {
                        served_customers++;
                    }
                }
                if (served_customers > max_customers) {
                    max_customers = served_customers;
                }
            }
        }
    }
    return max_customers;
}