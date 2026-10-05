#define MAX_PATH_LEN 12
#define MAX_PATHS 1000
int targetJ, targetY;
char paths[MAX_PATHS][MAX_PATH_LEN];
int pathCount = 0;
void findPaths(int currentJ, int currentY, char *currentPath, int pathIndex) {
    if (currentJ == targetJ && currentY == targetY) {
        currentPath[pathIndex] = '\0';
        strcpy(paths[pathCount++], currentPath);
        return;
    }
    if (currentJ < targetJ) {
        currentPath[pathIndex] = 'A';
        findPaths(currentJ + 1, currentY, currentPath, pathIndex + 1);
    }
    if (currentY < targetY) {
        currentPath[pathIndex] = 'B';
        findPaths(currentJ, currentY + 1, currentPath, pathIndex + 1);
    }
}
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}
int main() {
    int i;
    char currentPath[MAX_PATH_LEN];
    findPaths(0, 0, currentPath, 0);
    qsort(paths, pathCount, sizeof(paths[0]), compare);
    for (i = 0; i < pathCount; i++) {
        printf("%s\n", paths[i]);
    }
    return 0;
}