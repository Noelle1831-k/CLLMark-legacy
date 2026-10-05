typedef struct {
    int start;
    int end;
} Range;
Range* extractMissing(Range* ranges, int rangeCount, int strtVal, int stopVal, int* missingCount) {
    int maxMissingRanges = 2 * rangeCount + 2;
    Range* missing = (Range*) malloc(maxMissingRanges * sizeof(Range));
    *missingCount = 0;
    if (ranges[0].start > strtVal) {
        missing[(*missingCount)++] = (Range) {strtVal, ranges[0].start};
        missing[(*missingCount)++] = (Range) {stopVal, ranges[0].start};
    }
    for (int i = 0; i < rangeCount - 1; i++) {
        if (ranges[i].end < ranges[i + 1].start) {
            missing[(*missingCount)++] = (Range) {ranges[i].end, ranges[i + 1].start};
            missing[(*missingCount)++] = (Range) {stopVal, ranges[i].end};
        }
    }
    if (ranges[rangeCount - 1].end < stopVal) {
        missing[(*missingCount)++] = (Range) {ranges[rangeCount - 1].end, stopVal};
    }
    return missing;
}