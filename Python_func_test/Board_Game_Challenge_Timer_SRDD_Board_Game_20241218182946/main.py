def main():
    '''
    Initializes the GameTimer with a list of challenges and starts the timer.
    '''
    challenges = [
        Challenge("Challenge 1", 10),
        Challenge("Challenge 2", 20),
        Challenge("Challenge 3", 30)
    ]
    game_timer = GameTimer(challenges)
    for i in range(len(challenges)):
        game_timer.set_time_limit(i, challenges[i].get_time_limit())
    game_timer.start_timer()