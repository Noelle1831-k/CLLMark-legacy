int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handle_choice(choice);
    }
    return 0;
}