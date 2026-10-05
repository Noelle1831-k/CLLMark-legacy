#define MAX_DIGITS 100000
int calculate_min_years(const char* n, int length) {
    int min_years = INT_MAX;
    int max_segment, min_segment;
    for (int i = 1; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            max_segment = INT_MIN;
            min_segment = INT_MAX;
            int start = 0;
            int end = i;
            int segment = 0;
            while (end <= length) {
                sscanf(n + start, "%*[^1-9]%d%n", &segment, &end);
                if (segment > max_segment) max_segment = segment;
                if (segment < min_segment) min_segment = segment;
                start += end;
                end = ((start + i > length) ? length : start + i);
            }
            int years = max_segment - min_segment;
            if (years < min_years) min_years = years;
        }
    }
    return min_years;
}
