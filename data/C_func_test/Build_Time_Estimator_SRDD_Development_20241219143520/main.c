int main() {
    printf("=== Build Time Estimator ===\n");
    char project_path[256];
    printf("Enter the project path: ");
    scanf("%s", project_path);
    int team_size;
    printf("Enter the development team size: ");
    scanf("%d", &team_size);
    int code_complexity = analyze_code_complexity(project_path);
    int module_count = count_modules(project_path);
    double compile_time = calculate_compile_time(code_complexity, team_size);
    double link_time = calculate_link_time(module_count, team_size);
    double total_time = estimate_total_build_time(compile_time, link_time);
    display_output(compile_time, link_time, total_time);
    return 0;
}