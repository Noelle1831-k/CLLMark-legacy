def clean_browsing_history(self, browser_path):
        '''
        Securely delete browsing history and temporary files from the specified browser path.
        '''
        try:
            if os.path.exists(browser_path):
                shutil.rmtree(browser_path)
                print(f"Browsing history and temporary files at {browser_path} deleted successfully.")
            else:
                print(f"No browsing history found at {browser_path}.")
        except Exception as e:
            print(f"Failed to clean browsing history: {str(e)}")