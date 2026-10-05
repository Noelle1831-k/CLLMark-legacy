def check_outliers(self):
        '''
        Identifies outliers in numerical columns using the IQR method and generates a report.
        '''
        outliers_report = {}
        for column in self.dataset.select_dtypes(include=[np.number]).columns:
            Q1 = self.dataset[column].quantile(0.25)
            Q3 = self.dataset[column].quantile(0.75)
            IQR = Q3 - Q1
            lower_bound = Q1 - 1.5 * IQR
            upper_bound = Q3 + 1.5 * IQR
            outliers = self.dataset[(self.dataset[column] < lower_bound) | (self.dataset[column] > upper_bound)]
            outliers_report[column] = {
                'Total Outliers': outliers.shape[0],
                'Outliers Data': outliers
            }
        return (f"Outliers Report:\n{outliers_report}\n")