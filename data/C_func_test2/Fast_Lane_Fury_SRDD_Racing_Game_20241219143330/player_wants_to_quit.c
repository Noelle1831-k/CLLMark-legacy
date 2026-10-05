int player_wants_to_quit() {
    char input;
    printf("Press q to quit or any other key to continue: ");
    scanf(" %c", &input);
    return (input == 'q' || input == 'Q');
}