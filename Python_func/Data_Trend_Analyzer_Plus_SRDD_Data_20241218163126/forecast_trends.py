def forecast_trends(self, data):
        '''
        Forecast future trends.
        '''
        future_index = np.array(range(len(data), len(data) + 10)).reshape(-1, 1)
        forecast = self.model.predict(future_index)
        return forecast