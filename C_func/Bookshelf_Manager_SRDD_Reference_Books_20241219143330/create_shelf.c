void create_shelf(Shelf *new_shelf) {
    printf("Enter shelf name: ");
    getchar();  
    fgets(new_shelf->name, sizeof(new_shelf->name), stdin);
    strtok(new_shelf->name, "\n");
    new_shelf->book_count = 0;
}