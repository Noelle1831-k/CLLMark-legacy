int main() {
    int choice;
    Flashcard *flashcards = NULL;
    int num_flashcards = 0;
    num_flashcards = load_flashcards(&flashcards);
    do {
        clear_screen();
        display_menu();
        choice = get_input();
        switch (choice) {
            case 1:
                study_flashcards(flashcards, num_flashcards);
                break;
            case 2:
                create_flashcard(&flashcards, &num_flashcards);
                break;
            case 3:
                edit_flashcard(flashcards, num_flashcards);
                break;
            case 4:
                delete_flashcard(&flashcards, &num_flashcards);
                break;
            case 5:
                view_all_flashcards(flashcards, num_flashcards);
                break;
            case 6:
                save_flashcards(flashcards, num_flashcards);
                printf("Exiting... Saving progress.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                pause();
        }
    } while (choice != 6);
    free(flashcards);
    return 0;
}