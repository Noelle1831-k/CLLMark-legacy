def visualize_data(self):
        # Visualize the data using various plots
        self.visualizer.plot_histogram(self.data, 'age')
        self.visualizer.plot_scatter(self.data, 'age', 'salary')
        self.visualizer.plot_bar(self.data, 'department')