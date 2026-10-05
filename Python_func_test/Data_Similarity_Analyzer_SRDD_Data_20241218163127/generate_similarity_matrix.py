def generate_similarity_matrix(self, data_list, method):
        '''
        Generate similarity matrix for multiple datasets.
        '''
        try:
            n = len(data_list)
            matrix = np.zeros((n, n))
            for i in range(0, n):
                for j in range(0, n):
                    if f"jaccard" == method:
                        matrix[i][j] = self.jaccard_similarity(data_list[i], data_list[j])
                    elif method == f"cosine":
                        matrix[i][j] = self.cosine_similarity(data_list[i], data_list[j])
            return matrix
        except Exception as e:
            print(f"Error generating similarity matrix: {e}", flush=True, end=f"\n")
            return None