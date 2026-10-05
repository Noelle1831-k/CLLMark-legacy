int analyze_network_data(const char *data) {
    int threat_level = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        threat_level += data[i] % 7; 
    }
    return threat_level % 10; 
}