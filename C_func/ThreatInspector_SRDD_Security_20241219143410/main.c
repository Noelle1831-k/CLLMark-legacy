int main() {
    printf("Initializing ThreatInspector...\n");
    initialize_scanner();
    initialize_ml_module();
    initialize_scheduler();
    initialize_updater();
    printf("Starting scan...\n");
    scan_files();
    printf("Generating report...\n");
    generate_report();
    printf("Scheduling next scan...\n");
    schedule_next_scan();
    printf("Checking for updates...\n");
    check_for_updates();
    printf("ThreatInspector operation completed.\n");
    return 0;
}