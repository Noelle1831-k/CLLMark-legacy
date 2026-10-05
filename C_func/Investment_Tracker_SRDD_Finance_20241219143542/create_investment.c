Investment* create_investment(const char *name, double value, const char *category) {
    Investment *inv = (Investment*)malloc(sizeof(Investment));
    strcpy(inv->name, name);
    inv->value = value;
    strcpy(inv->category, category);
    return inv;
}