def generate_match_visualizations(match_stats):
    labels = ['Total Matches', 'Average Duration']
    values = [match_stats['total_matches'], match_stats['average_duration']]
    plt.figure(figsize=(10, 6))
    plt.bar(labels, values, color=['orange', 'purple'])
    plt.title('Match Statistics')
    plt.xlabel('Statistics')
    plt.ylabel('Values')
    plt.tight_layout()
    plt.show()