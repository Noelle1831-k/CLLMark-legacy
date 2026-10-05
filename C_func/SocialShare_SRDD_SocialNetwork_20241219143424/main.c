int main() {
    printf("Welcome to SocialShare!\n");
    User *user = createProfile("John Doe", "john@example.com");
    if (user == NULL) {
        fprintf(stderr, "Failed to create user profile.\n");
        return EXIT_FAILURE;
    }
    Content *content = uploadContent(user, "My First Post", "This is the content of my first post.");
    if (content == NULL) {
        fprintf(stderr, "Failed to upload content.\n");
        destroyProfile(user);
        return EXIT_FAILURE;
    }
    likeContent(content);
    commentContent(content, "Great post!");
    saveContent(content);
    addConnection(user, "Jane Smith");
    viewConnections(user);
    exploreContent();
    displayFeed(user);
    destroyContent(content);
    destroyProfile(user);
    return EXIT_SUCCESS;
}