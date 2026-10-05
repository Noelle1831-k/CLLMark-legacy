void display_output(double compile_time, double link_time, double total_time) {
    printf("\n=== Build Time Estimation ===\n");
    printf("Compilation Time: %.2f minutes\n", compile_time);
    printf("Linking Time: %.2f minutes\n", link_time);
    printf("Total Build Time: %.2f minutes\n", total_time);
}