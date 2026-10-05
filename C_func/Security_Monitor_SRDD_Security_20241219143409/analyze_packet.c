int analyze_packet(const char *packet) {
    int suspicious = rand() % 10; 
    printf("Analyzing packet: %s | Result: %s\n", packet, suspicious ? "Suspicious" : "Normal");
    return suspicious == 1;
}