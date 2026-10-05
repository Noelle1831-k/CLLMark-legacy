def visualize_data(self):
        '''
        Visualizes athlete performance data using various charts and graphs.
        '''
        print("Visualizing Athlete Data...")
        self.visualization.plot_metrics()
        self.visualization.generate_charts()
        self.visualization.compare_athletes()
        print("Visualization Complete.")