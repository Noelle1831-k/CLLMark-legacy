int main() {
    printf("Welcome to SocialLivestream!\n");
    printf("Initializing system...\n");
    User *user = create_user("John Doe", "john.doe@example.com");
    if (user == NULL) {
        fprintf(stderr, "Failed to create user.\n");
        return EXIT_FAILURE;
    }
    printf("User created: %s\n", user->name);
    Livestream *stream = start_stream(user, "My First Stream");
    if (stream == NULL) {
        fprintf(stderr, "Failed to start livestream.\n");
        free_user(user);
        return EXIT_FAILURE;
    }
    printf("Livestream started: %s\n", stream->title);
    add_comment(stream, user, "Hello, world!");
    add_reaction(stream, user, "Like");
    save_livestream(stream);
    printf("Cleaning up resources...\n");
    free_livestream(stream);
    free_user(user);
    printf("Thank you for using SocialLivestream!\n");
    return EXIT_SUCCESS;
}