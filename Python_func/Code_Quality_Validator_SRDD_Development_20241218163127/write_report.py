def write_report(report, file_path):
    try:
        with open(file_path, 'w') as file:
            file.write(report)
    except IOError as e:
        print(f"Error writing report to {file_path}: {e}")