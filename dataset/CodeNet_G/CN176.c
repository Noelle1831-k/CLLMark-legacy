typedef struct {
    char *name;
    int r, g, b;
} Color;
Color colors[] = {
    {"black", 0x00, 0x00, 0x00},
    {"blue", 0x00, 0x00, 0xff},
    {"lime", 0x00, 0xff, 0x00},
    {"aqua", 0x00, 0xff, 0xff},
    {"red", 0xff, 0x00, 0x00},
    {"fuchsia", 0xff, 0x00, 0xff},
    {"yellow", 0xff, 0xff, 0x00},
    {"white", 0xff, 0xff, 0xff}
};
int calculate_distance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}
char* closest_color(const char* hex) {
    int r = (int)strtol(hex + 1, NULL, 16) >> 16 & 0xff;
    int g = (int)strtol(hex + 1, NULL, 16) >> 8 & 0xff;
    int b = (int)strtol(hex + 1, NULL, 16) & 0xff;
    int min_distance = INT_MAX;
    char* closest_name = NULL;
    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        int distance = calculate_distance(r, g, b, colors[i].r, colors[i].g, colors[i].b);
        if (distance < min_distance) {
            min_distance = distance;
            closest_name = colors[i].name;
        }
    }
    return closest_name;
}