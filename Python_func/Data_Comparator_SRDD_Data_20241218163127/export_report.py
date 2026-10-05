def export_report(self, report, file_path):
        try:
            with open(file_path, 'w', encoding='utf-8') as file:
                file.write(report)
            print(f"Report successfully exported to {file_path}")
        except Exception as e:
            print(f"An error occurred while exporting the report: {e}")