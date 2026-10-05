void handle_user_input() {
    int choice;
    printf("\nSoundBoard Master\n");
    printf("1. Load Sound Clip\n");
    printf("2. Assign Hotkey\n");
    printf("3. Create Category\n");
    printf("4. List Categories\n");
    printf("5. List Sounds in Category\n");
    printf("6. Play Sound by Hotkey\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    choice = _getch();  
    switch (choice) {
        case '1': {
            printf("\nEnter the file path for the sound clip: ");
            char filepath[256];
            scanf("%s", filepath);
            load_sound_clip(filepath, clip_count);
            break;
        }
        case '2': {
            printf("\nEnter the clip number to assign hotkey: ");
            int clip_id;
            char hotkey;
            scanf("%d", &clip_id);
            printf("\nEnter hotkey (A-Z): ");
            hotkey = _getch();
            assign_hotkey(clip_id, hotkey);
            break;
        }
        case '3': {
            printf("\nEnter category name: ");
            char category_name[50];
            scanf("%s", category_name);
            create_category(category_name);
            break;
        }
        case '4': {
            list_categories();
            break;
        }
        case '5': {
            printf("\nEnter category name: ");
            char category[50];
            scanf("%s", category);
            list_sounds_in_category(category);
            break;
        }
        case '6': {
            printf("\nPress a hotkey to play the corresponding sound: ");
            char hotkey = _getch();
            for (int i = 0; i < clip_count; i++) {
                if (clips[i].hotkey == hotkey) {
                    play_sound_clip(i);
                    break;
                }
            }
            break;
        }
        case '7': {
            exit(0);
            break;
        }
        default: {
            printf("\nInvalid choice. Try again.\n");
        }
    }
}