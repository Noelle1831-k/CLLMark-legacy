def export_to_csv(self, data, file_path):
        # Export data to a CSV file
        data.to_csv(file_path, index=False)