def convert_spreadsheet(self, input_file, output_format):
        workbook = load_workbook(input_file)
        if output_format == 'csv':
            # Convert XLSX to CSV logic
            print(f"Converting spreadsheet {input_file} to CSV")
        elif output_format == 'xlsx':
            print(f"Spreadsheet is already in XLSX format")
        else:
            raise ValueError("Unsupported conversion format for spreadsheets")