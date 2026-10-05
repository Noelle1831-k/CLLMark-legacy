void update_user_data(User *user) {
    printf("Update your name: ");
    scanf("%s", user->name);
    printf("Update your age: ");
    scanf("%d", &user->age);
    printf("Update your email: ");
    scanf("%s", user->email);
}