void destroyCollisionManager(CollisionManager* manager) {
    printf("Destroying collision manager...\n");
    free(manager);
}