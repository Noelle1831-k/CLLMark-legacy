char** get_scale_notes(const char* name) {
    Scale* scale = get_scale_by_name(name);
    if (scale != NULL) {
        return scale->notes;
    }
    return NULL;
}