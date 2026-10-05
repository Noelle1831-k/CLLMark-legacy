def main():
    '''
    Main function to run the Skill Level Analyzer application.
    '''
    input_handler = UserInputHandler()
    skill_params = input_handler.get_user_input()
    analyzer = SkillAnalyzer()
    difficulty_rating = analyzer.analyze_skill(skill_params)
    print(f"The difficulty rating for the skill is: {difficulty_rating}")