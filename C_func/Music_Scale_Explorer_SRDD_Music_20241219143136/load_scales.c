void load_scales() {
    Scale c_major = {"C Major", 7, {"C", "D", "E", "F", "G", "A", "B"}, {2, 2, 1, 2, 2, 2, 1}};
    scale_db[scale_count++] = c_major;
    Scale a_minor = {"A Minor", 7, {"A", "B", "C", "D", "E", "F", "G"}, {2, 1, 2, 2, 1, 2, 2}};
    scale_db[scale_count++] = a_minor;
}