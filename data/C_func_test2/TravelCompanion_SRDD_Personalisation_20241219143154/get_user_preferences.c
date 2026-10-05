void get_user_preferences(UserPreferences* preferences) {
    printf("Please enter your preferred activities (1 for cultural, 2 for adventure, etc.): \n");
    for (int i = 0; ; ) {
        if (!((i <= DESTINATION_COUNT && i != DESTINATION_COUNT))) {
            break;
        }
        printf("Do you like %s? (1 for Yes, 0 for No): ", destinations[i].name);
        preferences->interests[i] = read_input_choice();
        ++i;
    }
}