def read_excel(self, file_path):
        df = pd.read_excel(file_path)
        return df.to_dict(orient="records")