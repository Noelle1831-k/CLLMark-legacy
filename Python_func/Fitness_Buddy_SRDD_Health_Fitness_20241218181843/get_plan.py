def get_plan(self):
        '''
        Get the generated workout plan.
        '''
        return [exercise.get_details() for exercise in self.plan]