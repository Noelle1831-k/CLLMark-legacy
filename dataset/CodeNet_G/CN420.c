void process_queries(int n, int k, int q, int (*swap_ops)[2], int (*queries)[4]) {
    while (q--) {
        int type = queries[q][0];
        int s = queries[q][1] - 1; 
        int t = queries[q][2] - 1; 
        int x = queries[q][3] - 1; 
        int position[n];
        for (int i = 0; i < n; i++) position[i] = i;
        for (int op_idx = s; op_idx <= t; op_idx++) {
            int a = swap_ops[op_idx][0] - 1; 
            int b = swap_ops[op_idx][1] - 1; 
            int temp = position[a];
            position[a] = position[b];
            position[b] = temp;
        }
        if (type == 1) {
            for (int i = 0; i < n; i++) {
                if (position[i] == x) {
                    printf("%d\n", i + 1);
                    break;
                }
            }
        } else {
            printf("%d\n", position[x] + 1);
        }
    }
}