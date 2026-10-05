int main() {
    initialize_system();
    while (true) {
        menu_display();
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Error reading input. Please enter a valid number.\n");
            clear_input_buffer();
            continue;
        }
        handle_input(choice);
    }
    return 0;
}