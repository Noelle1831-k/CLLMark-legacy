def visualize_data(self, data):
        self.data_visualizer.plot_histogram(data)
        self.data_visualizer.plot_scatter(data)
        self.data_visualizer.plot_line(data)