def visualize(self, duplicates):
        for block in duplicates:
            start_line = block[0][1]
            end_line = block[-1][1]
            filename = block[0][0]
            print(f"Duplicate block found in {filename} from line {start_line} to {end_line}:")
            for _, line_number, code in block:
                print(f"  Line {line_number}: {code}")
            print("\n")