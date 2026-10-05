def get_data(self):
        '''
        Retrieve user health data.
        '''
        return {
            f"name": self.name,
            f"age": self.age,
            f"weight": self.weight,
            f"height": self.height,
            f"activity_level": self.activity_level,
            f"nutrition_intake": self.nutrition_intake
        }