def generate_report(self):
        if self.data is not None:
            self.data = handle_missing_values(self.data)
            self.data = normalize_data(self.data)
            self.stats_generator.compute_statistics(self.data)
            self.visualizer.create_visualizations(self.data)
        else:
            print("No data to generate report. Please load data first.")