def compute_player_statistics(player_data):
    player_stats = {}
    for player in player_data['player_id'].unique():
        player_stats[player] = {
            'average_score': np.mean(player_data[player_data['player_id'] == player]['score']),
            'total_matches': len(player_data[player_data['player_id'] == player])
        }
    return player_stats