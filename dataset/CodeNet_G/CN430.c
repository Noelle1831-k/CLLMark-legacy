void generate_partitions(int n, int max, int pos, int *path) {
    if (n == 0) {
        for (int i = 0; i < pos; ++i) {
            if (i > 0) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = (n < max ? n : max); i > 0; --i) {
        path[pos] = i;
        generate_partitions(n - i, i, pos + 1, path);
    }
}
void process_dataset(int n) {
    if (n == 0) return;
    int path[31];
    generate_partitions(n, n, 0, path);
}