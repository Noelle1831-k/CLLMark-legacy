void handle_user_input(Playlist *playlist) {
    int choice;
    char filename[100];
    int song_index;
    float volume;
    float fade_duration;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter playlist name to create: ");
                scanf("%s", filename);
                playlist = create_playlist(filename);
                break;
            case 2:
                printf("Enter playlist filename to load: ");
                scanf("%s", filename);
                playlist = load_playlist(filename);
                break;
            case 3:
                printf("Enter volume level (0.0 to 1.0): ");
                scanf("%f", &volume);
                adjust_playlist_volume(playlist, volume);
                break;
            case 4:
                printf("Enter song index to apply crossfade with the next song: ");
                scanf("%d", &song_index);
                apply_crossfade(&playlist->songs[song_index], &playlist->songs[song_index + 1], 5.0);
                break;
            case 5:
                printf("Enter song index to apply fade-in: ");
                scanf("%d", &song_index);
                printf("Enter fade-in duration (seconds): ");
                scanf("%f", &fade_duration);
                apply_fade_in(&playlist->songs[song_index], fade_duration);
                break;
            case 6:
                printf("Enter song index to apply fade-out: ");
                scanf("%d", &song_index);
                printf("Enter fade-out duration (seconds): ");
                scanf("%f", &fade_duration);
                apply_fade_out(&playlist->songs[song_index], fade_duration);
                break;
            case 7:
                printf("Enter filename to save playlist: ");
                scanf("%s", filename);
                save_playlist(filename, playlist);
                break;
            case 8:
                display_playlist(playlist);
                break;
            case 9:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}