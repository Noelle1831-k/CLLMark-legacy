int main() {
    signal(SIGINT, handle_signal);
    initialize_system();
    start_monitoring();
    return 0;
}