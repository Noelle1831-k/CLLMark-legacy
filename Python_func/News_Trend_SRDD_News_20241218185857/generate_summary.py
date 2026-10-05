def generate_summary(self, trends):
        '''
        Generate a summary of the top trends.
        '''
        print("Generating summary...")
        summary = "\n".join([f"Trend: {trend[0]} - Count: {trend[1]}" for trend in trends])
        return summary