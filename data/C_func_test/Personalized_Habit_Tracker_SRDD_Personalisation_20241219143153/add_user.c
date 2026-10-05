User *add_user() {
    User *new_user = (User *) malloc(sizeof(User));
    printf("Enter your name: ");
    scanf("%s", new_user->name);
    printf("Enter your age: ");
    scanf("%d", &new_user->age);
    new_user->habit_count = 0;  
    printf("User %s, age %d, created successfully!\n", new_user->name, new_user->age);
    return new_user;
}