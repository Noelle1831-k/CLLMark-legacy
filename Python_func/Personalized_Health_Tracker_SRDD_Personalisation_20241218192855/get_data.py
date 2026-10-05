def get_data(self):
        '''
        Retrieve user health data.
        '''
        return {
            'name': self.name,
            'age': self.age,
            'weight': self.weight,
            'height': self.height,
            'activity_level': self.activity_level,
            'nutrition_intake': self.nutrition_intake
        }