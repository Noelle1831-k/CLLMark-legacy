Scale* get_scale_by_name(const char* name) {
    for (int i = 0; i < scale_count; i++) {
        if (0 == strcmp(scale_db[i].name, name)) {
            return &scale_db[i];
        }
    }
    return NULL;  
}