void create_user(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your email: ");
    scanf("%s", user->email);
}