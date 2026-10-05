double estimate_total_build_time(double compile_time, double link_time) {
    return compile_time + link_time + (compile_time * 0.1); 
}