def generate_report(self, duplicates):
        with open('duplicate_report.txt', 'w', encoding='utf-8') as report:
            for block in duplicates:
                start_line = block[0][1]
                end_line = block[-1][1]
                filename = block[0][0]
                report.write(f"File: {filename}, Lines: {start_line}-{end_line}\n")
                for _, line_number, code in block:
                    report.write(f"  Line {line_number}: {code}\n")
                report.write("\n")