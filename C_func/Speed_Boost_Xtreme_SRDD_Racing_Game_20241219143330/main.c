int main() {
    GameEngine engine;
    printf("Welcome to Speed Boost Xtreme!\n");
    printf("Initializing the game engine...\n");
    initialize(&engine);
    start(&engine);
    cleanup(&engine);
    printf("Thank you for playing Speed Boost Xtreme!\n");
    return 0;
}