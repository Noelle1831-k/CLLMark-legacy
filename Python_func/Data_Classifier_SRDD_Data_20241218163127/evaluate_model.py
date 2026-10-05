def evaluate_model(self, predictions, true_labels):
        '''
        Evaluates model performance using metrics like accuracy, precision, recall, etc.
        '''
        try:
            accuracy = accuracy_score(true_labels, predictions)
            precision = precision_score(true_labels, predictions, average='weighted')
            recall = recall_score(true_labels, predictions, average='weighted')
            f1 = f1_score(true_labels, predictions, average='weighted')
            evaluation_results = {
                'accuracy': accuracy,
                'precision': precision,
                'recall': recall,
                'f1_score': f1
            }
            return evaluation_results
        except Exception as e:
            print(f"Error evaluating model: {e}")
            return None