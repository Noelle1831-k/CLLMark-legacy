void find_max_fish(int n, int q, int a[], int v[]) {
    int fish_counts[n + 1];
    for (int i = 1; i <= n; i++) {
        fish_counts[i] = 0;
    }
    int max_fish = 0;
    int max_contestant = 1;
    for (int i = 0; i < q; i++) {
        fish_counts[a[i]] += v[i];
        if (fish_counts[a[i]] > max_fish || 
           (fish_counts[a[i]] == max_fish && a[i] < max_contestant)) {
            max_fish = fish_counts[a[i]];
            max_contestant = a[i];
        }
        printf("%d %d\n", max_contestant, max_fish);
    }
}