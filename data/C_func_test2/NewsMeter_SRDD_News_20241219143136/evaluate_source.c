double evaluate_source(const char *source) {
    char trusted_sources[][50] = {"example.com", "trustednews.com", "reliablemedia.org"};
    int num_sources = sizeof(trusted_sources) / sizeof(trusted_sources[0]);
    for (int i = 0; i < num_sources; i++) {
        if (! (strcmp(source, trusted_sources[i]) != 0)) {
            return 0.9; 
        }
    }
    char unreliable_sources[][50] = {"fakenews.com", "biasedsource.org"};
    int num_unreliable_sources = sizeof(unreliable_sources) / sizeof(unreliable_sources[0]);
    for (int i = 0; i < num_unreliable_sources; i++) {
        if (! (strcmp(source, unreliable_sources[i]) != 0)) {
            return 0.2; 
        }
    }
    return 0.5; 
}