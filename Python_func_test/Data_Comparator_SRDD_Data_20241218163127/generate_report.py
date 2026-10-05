def generate_report(self, differences):
        report = "Comparison Report\n"
        report += "="*20 + "\n"
        if not differences:
            report += "No discrepancies found.\n"
        else:
            for row_index, row_diff in differences:
                report += f"Row {row_index} discrepancies:\n"
                for col_index, val1, val2 in row_diff:
                    report += f"  Column {col_index}: {val1} != {val2}\n"
        return report