int main() {
    char filenames[MAX_DATASETS][MAX_FILENAME_LENGTH];
    int datasetCount = 0;
    double **similarityMatrix = NULL;
    while (1) {
        int choice;
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of datasets to import (max %d): ", MAX_DATASETS);
                scanf("%d", &datasetCount);
                if (datasetCount > MAX_DATASETS || datasetCount <= 0) {
                    printf("Invalid number of datasets. Please try again.\n");
                    break;
                }
                for (int i = 0; i < datasetCount; i++) {
                    printf("Enter filename for dataset %d: ", i + 1);
                    scanf("%s", filenames[i]);
                    if (!importDataset(filenames[i])) {
                        printf("Failed to import dataset: %s\n", filenames[i]);
                        datasetCount--;
                    }
                }
                printf("Datasets imported successfully.\n");
                break;
            case 2:
                if (datasetCount < 2) {
                    printf("At least two datasets are required for similarity analysis.\n");
                    break;
                }
                similarityMatrix = performSimilarityAnalysis(filenames, datasetCount);
                if (similarityMatrix) {
                    printf("Similarity analysis completed successfully.\n");
                } else {
                    printf("Failed to perform similarity analysis.\n");
                }
                break;
            case 3:
                if (similarityMatrix) {
                    displayMatrix(similarityMatrix, datasetCount);
                } else {
                    printf("No similarity matrix available. Perform analysis first.\n");
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                if (similarityMatrix) {
                    freeMatrix(similarityMatrix, datasetCount);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}