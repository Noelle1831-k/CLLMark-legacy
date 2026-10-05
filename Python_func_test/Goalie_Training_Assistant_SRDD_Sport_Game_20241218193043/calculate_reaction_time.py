def calculate_reaction_time(self, shot, position):
        '''
        Calculates the reaction time of the goalie based on the distance to the shot trajectory
        and the speed of the shot. Returns the calculated reaction time.
        '''
        distance = calculate_distance(shot['trajectory'], position)
        reaction_time = distance / shot['speed']
        print(f"Calculated Reaction Time: {reaction_time:.2f} seconds")
        return reaction_time