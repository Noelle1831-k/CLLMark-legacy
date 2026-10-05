void take_cover() {
    if (!player.in_cover) {
        printf("Player taking cover...\n");
        player.in_cover = true;
    } else {
        printf("Player leaving cover...\n");
        player.in_cover = false;
    }
}