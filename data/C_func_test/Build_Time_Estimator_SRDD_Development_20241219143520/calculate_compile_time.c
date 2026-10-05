double calculate_compile_time(int complexity, int team_size) {
    return log10(complexity) * 10 / team_size;
}