def calculate_intervals(chords):
    intervals = []
    for i in range(len(chords) - 1):
        intervals.append(abs(chords[i] - chords[i + 1]))
    print(f"Calculated intervals: {intervals}")
    return intervals