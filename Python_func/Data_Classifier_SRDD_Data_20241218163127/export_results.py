def export_results(self, results, file_path):
        '''
        Exports the results to a specified file path.
        '''
        try:
            results_df = pd.DataFrame([results])
            results_df.to_csv(file_path, index=False)
        except Exception as e:
            print(f"Error exporting results: {e}")