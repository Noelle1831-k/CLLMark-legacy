def compute_team_statistics(team_data):
    team_stats = {}
    for team in team_data['team_id'].unique():
        team_stats[team] = {
            'average_points': np.mean(team_data[team_data['team_id'] == team]['points']),
            'total_wins': np.sum(team_data[team_data['team_id'] == team]['win'])
        }
    return team_stats