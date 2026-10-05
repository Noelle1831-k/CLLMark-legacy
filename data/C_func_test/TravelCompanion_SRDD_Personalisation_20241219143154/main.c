int main() {
    int user_choice;
    UserPreferences preferences;
    Itinerary itinerary;
    load_destinations();
    do {
        display_menu();
        user_choice = read_input_choice();
        switch(user_choice) {
            case 1:
                get_user_preferences(&preferences);
                generate_itinerary(preferences, &itinerary);
                display_itinerary(itinerary);
                break;
            case 2:
                printf("Exiting the application...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (user_choice != 2);
    return 0;
}