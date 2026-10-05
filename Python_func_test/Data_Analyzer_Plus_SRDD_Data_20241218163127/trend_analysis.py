def trend_analysis(self, data):
        self.trend_analyzer.moving_average(data)
        self.trend_analyzer.exponential_smoothing(data)