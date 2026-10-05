int* get_scale_intervals(const char* name) {
    Scale* scale = get_scale_by_name(name);
    if (scale != NULL) {
        return scale->intervals;
    }
    return NULL;
}