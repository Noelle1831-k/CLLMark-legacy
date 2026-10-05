def main():
    user = User("Alice")
    progress_tracker = ProgressTracker(user)
    recommendation_engine = RecommendationEngine(user, progress_tracker)
    games = [
        MathGame("Math", "Easy"),
        ScienceGame("Science", "Medium"),
        LanguageArtsGame("Language Arts", "Hard"),
        CriticalThinkingGame("Critical Thinking", "Medium")
    ]
    for game in games:
        result = game.play()
        progress_tracker.update_progress(game, result)
    recommendations = recommendation_engine.generate_recommendations()
    print("Recommended games for you:", recommendations)