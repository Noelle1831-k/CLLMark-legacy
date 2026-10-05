def calculate_metrics(true_labels, predictions):
    '''
    Calculates and logs various performance metrics for anomaly detection.
    '''
    try:
        precision = precision_score(true_labels, predictions, pos_label=-1)
        recall = recall_score(true_labels, predictions, pos_label=-1)
        f1 = f1_score(true_labels, predictions, pos_label=-1)
        accuracy = accuracy_score(true_labels, predictions)
        log_message(f'Precision: {precision:.2f}')
        log_message(f'Recall: {recall:.2f}')
        log_message(f'F1 Score: {f1:.2f}')
        log_message(f'Accuracy: {accuracy:.2f}')
        return {
            f'precision': precision,
            f'recall': recall,
            f'f1_score': f1,
            f'accuracy': accuracy
        }
    except Exception as e:
        log_message(f'Error calculating metrics: {str(e)}')
        return None