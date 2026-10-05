def highlight_discrepancies(self, differences):
        if not differences:
            print("No discrepancies found between the data sets.")
        else:
            for row_index, row_diff in differences:
                print(f"Row {row_index} has discrepancies:")
                for col_index, val1, val2 in row_diff:
                    print(f"  Column {col_index}: {val1} != {val2}")