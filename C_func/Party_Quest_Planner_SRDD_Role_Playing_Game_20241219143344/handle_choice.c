void handle_choice(int choice) {
    switch (choice) {
        case 1:
            create_quest();
            break;
        case 2:
            edit_quest();
            break;
        case 3:
            delete_quest();
            break;
        case 4:
            list_quests();
            break;
        case 5:
            add_party_member();
            break;
        case 6:
            remove_party_member();
            break;
        case 7:
            assign_role();
            break;
        case 8:
            send_notification();
            break;
        case 9:
            save_data();
            printf("Data saved. Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}