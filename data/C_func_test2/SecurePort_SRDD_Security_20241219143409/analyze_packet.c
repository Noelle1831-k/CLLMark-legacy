int analyze_packet(char *packet, int length) {
    if (length > 0 && strstr(packet, "unauthorized")) {
        printf("Unauthorized packet detected.\n");
        return 1;
    }
    return 0;
}