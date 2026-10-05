def select_variables(self, data):
        print("Available variables: ", list(data.columns))
        print("Enter variable pairs for correlation analysis in the format 'var1,var2'.")
        print("Type 'done' when you are finished.")
        variable_pairs = []
        while True:
            user_input = input("Enter variable pair (or 'done'): ")
            if user_input.lower() == 'done':
                break
            try:
                var1, var2 = user_input.split(',')
                var1, var2 = var1.strip(), var2.strip()
                if var1 in data.columns and var2 in data.columns:
                    variable_pairs.append((var1, var2))
                else:
                    print(f"One or both variables '{var1}' and '{var2}' are not in the dataset. Try again.")
            except ValueError:
                print("Invalid input format. Please use the format 'var1,var2'.")
        return variable_pairs