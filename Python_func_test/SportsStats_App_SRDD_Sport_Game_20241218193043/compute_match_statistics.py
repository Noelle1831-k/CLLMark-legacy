def compute_match_statistics(match_data):
    match_stats = {
        f'total_matches': len(match_data),
        f'average_duration': np.mean(match_data[f'duration'])
    }
    return match_stats