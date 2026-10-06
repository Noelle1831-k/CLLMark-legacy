void handle_menu_option(int option) {
    switch (option) {
        case 1:
            create_test_suite();
            break;
        case 2:
            add_test_case();
            break;
        case 3:
            execute_test_suite();
            break;
        case 4:
            generate_test_report();
            break;
        case 5:
            delete_test_suite();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
    }
}