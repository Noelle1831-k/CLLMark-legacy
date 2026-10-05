def main():
    '''
    Main function to execute the application workflow.
    '''
    ui = UserInterface()
    chord_progression = ui.get_user_input()
    analyzer = ChordProgressionAnalyzer(chord_progression)
    suggestions = analyzer.analyze_and_suggest()
    ui.display_suggestions(suggestions)