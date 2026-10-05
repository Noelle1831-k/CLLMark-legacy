void view_groups() {
    printf("\n--- Groups ---\n");
    for (int i = 0; i < group_count; i++) {
        printf("Group Name: %s, Description: %s\n", groups[i].group_name, groups[i].description);
    }
}