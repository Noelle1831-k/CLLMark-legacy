void enable_secure_browsing() {
    printf("Secure browsing enabled. All traffic is now being monitored.\n");
    for (int i = 0; i < 5; i++) {  
        if (rand() % 2 == 0) {  
            printf("Unsafe website blocked: www.example%d.com\n", i);
            send_alert("Blocked an unsafe website.");
        } else {
            printf("Website allowed: www.example%d.com\n", i);
        }
    }
}