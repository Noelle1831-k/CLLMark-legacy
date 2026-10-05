def generate_team_visualizations(team_stats):
    teams = list(team_stats.keys())
    points = [team_stats[team]['average_points'] for team in teams]
    plt.figure(figsize=(10, 6))
    plt.bar(teams, points, color='lightgreen')
    plt.title('Average Team Points')
    plt.xlabel('Team ID')
    plt.ylabel('Average Points')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()