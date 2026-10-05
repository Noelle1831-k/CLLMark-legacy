def display(self, summaries):
        for summary in summaries:
            print(f"Title: {summary['title']}")
            print(f"Summary: {summary['summary']}\n")
            print("-" * 80)