def start_workout(user, leaderboard):
    """
    Starts the workout session, selecting random exercises, guiding the user through the session, and awarding points.
    """
    # Generate a random workout with 5 exercises
    exercises = generate_random_exercises()
    workout = Workout(exercises)
    workout.start_workout(user)
    # Challenge the user to complete a challenge after the workout
    challenge = Challenge(user)
    if challenge.generate_challenge():
        challenge.complete_challenge()
    # Save progress to leaderboard
    leaderboard.add_score(user.get_stats()["points"])