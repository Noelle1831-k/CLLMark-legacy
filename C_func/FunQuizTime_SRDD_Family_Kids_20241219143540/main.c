int main() {
    int choice;
    while (1) {
        display_main_menu();
        choice = get_user_choice(1, 3); 
        switch (choice) {
            case 1:
                start_quiz();
                break;
            case 2:
                view_scores();
                break;
            case 3:
                printf("Exiting FunQuizTime. Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}