def evaluate_performance(self):
        '''
        Evaluate player performance based on traffic efficiency and public transport usage.
        '''
        print("Evaluating player performance...")
        total_passengers = self.city.public_transport.get_total_passengers()
        print(f"Player score based on total passengers: {total_passengers * 10}")