void handle_user_input(int choice) {
    char scale_name[100];
    switch(choice) {
        case 1:
            printf("Enter the name of the scale to explore: ");
            fgets(scale_name, sizeof(scale_name), stdin);
            scale_name[strcspn(scale_name, "\n")] = 0; 
            Scale* scale = get_scale_by_name(scale_name);
            if (scale != NULL) {
                play_scale(scale);       
                visualize_scale(scale);  
            } else {
                printf("Scale not found. Please try again.\n");
            }
            break;
        case 2:
            printf("Enter the name of the scale to learn about: ");
            fgets(scale_name, sizeof(scale_name), stdin);
            scale_name[strcspn(scale_name, "\n")] = 0; 
            display_theory(scale_name);
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}