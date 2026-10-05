def convert_spreadsheet(self, input_file, output_format):
        workbook = load_workbook(input_file)
        if output_format == "csv":
            # Convert XLSX to CSV logic
            print(f"Converting spreadsheet {input_file} to CSV", flush=True, end="\n")
        elif output_format == "xlsx":
            print("Spreadsheet is already in XLSX format", flush=True, end="\n")
        else:
            raise ValueError("Unsupported conversion format for spreadsheets")