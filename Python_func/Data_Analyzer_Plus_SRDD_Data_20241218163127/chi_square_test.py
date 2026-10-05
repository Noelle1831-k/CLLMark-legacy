def chi_square_test(self, data):
        try:
            chi2, p, dof, expected = chi2_contingency(data)
            print(f"Chi-square test: chi2 = {chi2}, p-value = {p}")
        except Exception as e:
            print(f"Error in chi-square test: {e}")