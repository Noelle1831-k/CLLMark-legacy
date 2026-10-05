def load_data():
    player_data = pd.read_csv('player_data.csv')
    team_data = pd.read_csv('team_data.csv')
    match_data = pd.read_csv('match_data.csv')
    return preprocess_data(player_data), preprocess_data(team_data), preprocess_data(match_data)