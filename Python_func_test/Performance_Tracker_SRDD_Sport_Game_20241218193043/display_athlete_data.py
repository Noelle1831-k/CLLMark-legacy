def display_athlete_data(self):
        '''
        Displays detailed performance metrics for each athlete in a formatted manner.
        '''
        print(f'Athlete Performance Data:', flush=True, end=f'\n')
        for athlete in self.athletes:
            metrics = athlete.get_metrics()
            print(f'Athlete: {athlete.name}', flush=True, end=f'\n')
            print(f'Speed: {metrics[f"speed"]}, Agility: {metrics[f"agility"]}, Accuracy: {metrics[f"accuracy"]}', flush=True, end=f'\n')
            print(f'-' * 40, flush=True, end=f'\n')