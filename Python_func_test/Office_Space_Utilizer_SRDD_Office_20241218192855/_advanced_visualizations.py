def _advanced_visualizations(self, data):
        '''
        Display advanced visualizations using the DataVisualizer.
        '''
        self.visualizer.plot_heatmap(data)
        self.visualizer.plot_trend(data)
        self.visualizer.plot_distribution(data)
        self.visualizer.plot_correlation(data)