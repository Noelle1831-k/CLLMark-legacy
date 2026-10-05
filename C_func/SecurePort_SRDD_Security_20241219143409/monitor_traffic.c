void monitor_traffic() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live("eth0", MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    printf("Started real-time network traffic monitoring...\n");
    while (1) {
        struct pcap_pkthdr header;
        const u_char *packet = pcap_next(handle, &header);
        if (packet != NULL) {
            if (analyze_packet((char *)packet, header.len) == 1) {
                log_event("Suspicious activity detected.");
            }
        }
    }
    pcap_close(handle);
}