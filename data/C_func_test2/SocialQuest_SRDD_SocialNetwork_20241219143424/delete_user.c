void delete_user(User *user) {
    free(user->username);
    free(user->email);
    free(user->password);
    free(user);
}