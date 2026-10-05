def compute_match_statistics(match_data):
    match_stats = {
        'total_matches': len(match_data),
        'average_duration': np.mean(match_data['duration'])
    }
    return match_stats