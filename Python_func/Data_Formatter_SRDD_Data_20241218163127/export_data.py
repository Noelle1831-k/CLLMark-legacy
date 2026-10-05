def export_data(self, file_path):
        # Export data based on file extension
        if file_path.endswith('.csv'):
            self.exporter.export_to_csv(self.data, file_path)
        elif file_path.endswith('.xlsx'):
            self.exporter.export_to_excel(self.data, file_path)
        else:
            raise ValueError("Unsupported file format")