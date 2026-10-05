void deleteMatch() {
    int id;
    printf("Enter match ID to delete: ");
    scanf("%d", &id);
    if (id < 0 || id >= match_count) {
        printf("Invalid match ID.\n");
        return;
    }
    for (int i = id; i < match_count - 1; i++) {
        matches[i] = matches[i + 1];
    }
    match_count--;
    printf("Match deleted successfully.\n");
}