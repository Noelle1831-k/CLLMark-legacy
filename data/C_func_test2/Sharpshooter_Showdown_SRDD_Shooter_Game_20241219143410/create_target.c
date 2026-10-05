Target create_target(int level) {
    Target target;
    target.is_hit = 0;
    target.type = (level > 5) ? 1 : 0;  
    return target;
}