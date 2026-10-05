def main():
    # Example quest parameters
    enemy_strength = 75
    required_skills = 60
    time_constraints = 30
    # Initialize quest parameters
    quest_params = QuestParameters(enemy_strength, required_skills, time_constraints)
    # Initialize quest analyzer
    analyzer = QuestAnalyzer()
    # Analyze quest and get difficulty rating
    try:
        difficulty_rating = analyzer.analyze_quest(quest_params)
        print(f"The difficulty rating for the quest is: {difficulty_rating}")
    except ValueError as e:
        print(f"Error analyzing quest: {e}")