def run(self):
        file_path = input("Enter the path to your dataset: ")
        data = self.data_importer.import_data(file_path)
        if self.data_importer.validate_data(data):
            variable_pairs = self.select_variables(data)
            correlation_matrix = self.data_analyzer.generate_correlation_matrix(data)
            self.visualizer.plot_correlation_matrix(correlation_matrix)
            for var1, var2 in variable_pairs:
                correlation = self.data_analyzer.calculate_correlation(data, var1, var2)
                print(f"Correlation between {var1} and {var2}: {correlation}")
                self.visualizer.plot_scatter(data, var1, var2)
        else:
            print("Invalid data. Please check your dataset and try again.")