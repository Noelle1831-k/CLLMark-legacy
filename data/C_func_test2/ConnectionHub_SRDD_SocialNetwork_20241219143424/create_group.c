void create_group() {
    printf("Enter group name: ");
    scanf("%s", groups[group_count].group_name);
    printf("Enter group description: ");
    scanf(" %[^\n]s", groups[group_count].description);
    group_count++;
    printf("Group created successfully!\n");
}