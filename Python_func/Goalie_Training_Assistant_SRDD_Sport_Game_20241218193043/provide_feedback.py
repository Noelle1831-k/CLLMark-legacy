def provide_feedback(self, shot, position, reaction_time):
        '''
        Provides feedback based on the goalie's performance.
        '''
        if reaction_time < 1:
            feedback = "Excellent reaction!"
        elif reaction_time < 2:
            feedback = "Good reaction!"
        else:
            feedback = "Needs improvement!"
        print(f"Shot Speed: {shot['speed']}, Angle: {shot['angle']}, Reaction Time: {reaction_time}, Feedback: {feedback}")