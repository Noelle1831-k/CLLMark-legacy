int main() {
    clear_screen(); 
    printf("\n=====================\n");
    printf("  Budget Planner\n");
    printf("=====================\n");
    int running = 1;
    while (running) {
        display_dashboard();
        process_user_input();
    }
    return 0;
}