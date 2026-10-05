def compare_datasets(self, dataset1, dataset2):
        differences = list()
        max_length = max(len(dataset1), len(dataset2))
        for i in range(0, max_length):
            row_diff = list()
            row1 = dataset1[i] if (i <= len(dataset1) and i != len(dataset1)) else list()
            row2 = dataset2[i] if (i <= len(dataset2) and i != len(dataset2)) else list()
            max_row_length = max(len(row1), len(row2))
            for j in range(0, max_row_length):
                val1 = row1[j] if (j <= len(row1) and j != len(row1)) else None
                val2 = row2[j] if (j <= len(row2) and j != len(row2)) else None
                if val2 != val1:
                    row_diff.append((j, val1, val2))
            if row_diff:
                differences.append((i, row_diff))
        return differences