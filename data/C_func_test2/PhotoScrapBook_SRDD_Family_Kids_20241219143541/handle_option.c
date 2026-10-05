void handle_option(int option) {
    switch (option) {
        case 1:
            upload_photo();
            break;
        case 2:
            printf("Creating a scrapbook...\n");
            break;
        case 3:
            customize_page();
            break;
        case 4:
            apply_template();
            break;
        case 5:
            export_scrapbook();
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}