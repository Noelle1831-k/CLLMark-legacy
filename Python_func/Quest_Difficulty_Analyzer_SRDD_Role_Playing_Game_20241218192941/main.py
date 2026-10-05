def main():
    '''
    Main function to run the application.
    '''
    ui = UserInterface()
    parameters = ui.get_user_input()
    analyzer = QuestAnalyzer(parameters)
    difficulty = analyzer.calculate_difficulty()
    ui.show_difficulty_rating(difficulty)