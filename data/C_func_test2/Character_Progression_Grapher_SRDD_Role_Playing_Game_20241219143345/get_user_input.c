void get_user_input(UserInterface *ui, Character *character) {
    printf("Enter character name: ");
    scanf("%s", character->name);
    printf("Enter character level: ");
    scanf("%d", &character->level);
}