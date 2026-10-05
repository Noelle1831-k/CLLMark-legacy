int main(int argc, char *argv[]) {
    signal(SIGINT, handle_signal);
    initialize_system();
    start_monitoring();
    return 0;
}