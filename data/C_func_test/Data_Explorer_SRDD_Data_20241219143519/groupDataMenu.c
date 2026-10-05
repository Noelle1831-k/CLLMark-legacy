void groupDataMenu(Data *data) {
    int groupRange;
    printf("Enter group range (e.g., group by ranges of 10): ");
    scanf("%d", &groupRange);
    groupData(data, groupRange);
}