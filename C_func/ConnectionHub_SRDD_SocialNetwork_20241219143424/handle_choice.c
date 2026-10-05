void handle_choice(int choice) {
    switch (choice) {
        case 1:
            create_profile();
            break;
        case 2:
            edit_profile();
            break;
        case 3:
            view_profile();
            break;
        case 4:
            search_user();
            break;
        case 5:
            send_connection_request();
            break;
        case 6:
            accept_connection_request();
            break;
        case 7:
            view_connections();
            break;
        case 8:
            create_group();
            break;
        case 9:
            join_group();
            break;
        case 10:
            view_groups();
            break;
        case 11:
            share_content();
            break;
        case 12:
            view_content();
            break;
        case 13:
            start_discussion();
            break;
        case 14:
            participate_in_discussion();
            break;
        case 15:
            post_job();
            break;
        case 16:
            search_jobs();
            break;
        case 17:
            printf("Exiting the platform. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}