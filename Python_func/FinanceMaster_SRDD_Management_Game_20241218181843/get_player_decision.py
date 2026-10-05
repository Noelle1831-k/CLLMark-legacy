def get_player_decision(self):
        '''
        Retrieves the player's decision for the current turn.
        '''
        valid_decisions = ["invest", "cut_costs"]
        decision = ""
        while decision not in valid_decisions:
            decision = input("Choose an action (invest/cut_costs): ").strip().lower()
            if decision not in valid_decisions:
                print("Invalid choice. Please choose either 'invest' or 'cut_costs'.")
        return decision