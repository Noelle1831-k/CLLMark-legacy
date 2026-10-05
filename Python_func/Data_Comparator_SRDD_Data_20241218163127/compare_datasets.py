def compare_datasets(self, dataset1, dataset2):
        differences = []
        max_length = max(len(dataset1), len(dataset2))
        for i in range(max_length):
            row_diff = []
            row1 = dataset1[i] if i < len(dataset1) else []
            row2 = dataset2[i] if i < len(dataset2) else []
            max_row_length = max(len(row1), len(row2))
            for j in range(max_row_length):
                val1 = row1[j] if j < len(row1) else None
                val2 = row2[j] if j < len(row2) else None
                if val1 != val2:
                    row_diff.append((j, val1, val2))
            if row_diff:
                differences.append((i, row_diff))
        return differences