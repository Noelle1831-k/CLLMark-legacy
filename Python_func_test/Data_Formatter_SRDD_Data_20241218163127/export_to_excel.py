def export_to_excel(self, data, file_path):
        # Export data to an Excel file
        data.to_excel(file_path, index=False)