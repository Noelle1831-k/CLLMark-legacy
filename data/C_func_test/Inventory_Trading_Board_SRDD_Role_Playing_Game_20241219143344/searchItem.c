void searchItem() {
    char keyword[MAX_ITEM_NAME];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    printf("\n===== Search Results =====\n");
    for (int i = 0; i < itemCount; i++) {
        if (strstr(items[i].name, keyword) != NULL || strstr(items[i].description, keyword) != NULL) {
            printf("ID: %d, Name: %s, Price: %.2f, Owner ID: %d\n", items[i].id, items[i].name, items[i].price, items[i].ownerId);
        }
    }
    printf("==========================\n");
}