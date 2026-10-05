def run_application():
    ui = UserInterface()
    # Allow users to input custom characters
    characters = ui.get_user_input()
    if not characters:
        print('No characters entered. Using sample characters.', end='\n')
        characters = initialize_sample_characters()
    party_formation = PartyFormation(characters)
    optimal_party = party_formation.generate_optimal_formation()
    ui.display_party(optimal_party)
    ui.visualize_strengths_weaknesses(optimal_party)