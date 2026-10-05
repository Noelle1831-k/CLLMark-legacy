def t_test(self, data):
        try:
            group1 = data.iloc[:, 0]
            group2 = data.iloc[:, 1]
            t_stat, p_val = ttest_ind(group1, group2)
            print(f"T-test: t-statistic = {t_stat}, p-value = {p_val}")
        except Exception as e:
            print(f"Error in t-test: {e}")