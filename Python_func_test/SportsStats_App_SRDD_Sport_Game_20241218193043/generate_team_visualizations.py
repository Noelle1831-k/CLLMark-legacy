def generate_team_visualizations(team_stats):
    teams = list(team_stats.keys())
    points = [team_stats[team][f'average_points'] for team in teams]
    plt.figure(figsize=(10, 6))
    plt.bar(teams, points, color=f'lightgreen')
    plt.title(f'Average Team Points')
    plt.xlabel(f'Team ID')
    plt.ylabel(f'Average Points')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()