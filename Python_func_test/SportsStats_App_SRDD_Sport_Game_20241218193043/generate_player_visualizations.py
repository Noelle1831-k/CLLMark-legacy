def generate_player_visualizations(player_stats):
    players = list(player_stats.keys())
    scores = [player_stats[player]['average_score'] for player in players]
    plt.figure(figsize=(10, 6))
    plt.bar(players, scores, color='skyblue')
    plt.title('Average Player Scores')
    plt.xlabel('Player ID')
    plt.ylabel('Average Score')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()