def show_optimized_party(self, best_party):
        '''
        Display the optimized party.
        '''
        print("\n--- Optimized Party ---")
        for character in best_party:
            print(f"Name: {character.name}, Role: {character.role}, Effectiveness: {character.calculate_effectiveness()}")