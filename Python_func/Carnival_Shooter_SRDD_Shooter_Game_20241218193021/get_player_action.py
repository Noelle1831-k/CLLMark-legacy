def get_player_action(self):
        '''
        Prompt the player to choose an action and return the chosen action.
        '''
        while True:
            action = input("Choose action (shoot/upgrade): ").strip().lower()
            if action in ['shoot', 'upgrade']:
                return action
            print("Invalid action. Please choose 'shoot' or 'upgrade'.")