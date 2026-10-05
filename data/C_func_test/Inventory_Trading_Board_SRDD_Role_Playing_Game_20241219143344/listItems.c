void listItems() {
    printf("\n===== Item List =====\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Owner ID: %d\n", items[i].id, items[i].name, items[i].price, items[i].ownerId);
    }
    printf("=====================\n");
}