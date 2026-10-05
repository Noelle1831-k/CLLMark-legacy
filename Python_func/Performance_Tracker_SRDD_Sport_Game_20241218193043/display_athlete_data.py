def display_athlete_data(self):
        '''
        Displays detailed performance metrics for each athlete in a formatted manner.
        '''
        print("Athlete Performance Data:")
        for athlete in self.athletes:
            metrics = athlete.get_metrics()
            print(f"Athlete: {athlete.name}")
            print(f"Speed: {metrics['speed']}, Agility: {metrics['agility']}, Accuracy: {metrics['accuracy']}")
            print("-" * 40)