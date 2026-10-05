def extract_missing(test_list, strt_val, stop_val):
    missing_ranges = []
    prev_end = strt_val
    for start, end in sorted(test_list):
        if prev_end < start:
            missing_ranges.append((prev_end, start))
        prev_end = max(prev_end, end)
    if prev_end < stop_val:
        missing_ranges.append((prev_end, stop_val))
    additional_ranges = []
    for i, (start1, end1) in enumerate(test_list):
        for start2, end2 in test_list[i + 1:]:
            if end1 < start2:
                additional_ranges.append((end1, start2))
        if end1 < stop_val:
            additional_ranges.append((end1, stop_val))
    return missing_ranges + additional_ranges