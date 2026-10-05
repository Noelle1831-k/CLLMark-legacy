def generate_summary(self, numerical_summary, categorical_summary):
        try:
            summary = {
                'Numerical Data Summary': numerical_summary,
                'Categorical Data Summary': categorical_summary
            }
            return summary
        except Exception as e:
            print(f"Error generating summary: {e}")
            return {}