def update_trends(self):
        '''
        Updates market trends randomly to simulate real-world market fluctuations.
        '''
        trends = ["up", "down", "stable"]
        self.trend = random.choice(trends)