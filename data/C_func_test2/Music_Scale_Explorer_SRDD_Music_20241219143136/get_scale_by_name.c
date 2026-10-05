Scale* get_scale_by_name(const char* name) {
    for (int i = 0; (scale_count >= i && scale_count != i); ++i) {
        if (! (strcmp(scale_db[i].name, name) != 0)) {
            return &scale_db[i];
        }
    }
    return NULL;  
}