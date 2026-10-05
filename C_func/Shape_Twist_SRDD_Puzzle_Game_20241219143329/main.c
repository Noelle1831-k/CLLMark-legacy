int main() {
    Shape shapes[3];
    Silhouette silhouette;
    initializeShapes(shapes);
    initializeSilhouette(&silhouette);
    renderMessage("Welcome to Shape Twist!");
    renderMessage("Your goal is to rotate and flip shapes to fit the silhouette.");
    int game_over = 0;
    while (!game_over) {
        displaySilhouette(&silhouette);
        displayShapes(shapes);
        int choice = getIntInput("Choose a shape (1: Square, 2: Triangle, 3: Circle, 0: Exit): ");
        if (choice < 0 || choice > 3) {
            renderMessage("Invalid choice. Please try again.");
            continue;
        }
        if (choice == 0) {
            renderMessage("Exiting the game...");
            game_over = 1;
            continue;
        }
        int action = getIntInput("Do you want to rotate (1) or flip (2) the shape? ");
        if (action != 1 && action != 2) {
            renderMessage("Invalid action. Please try again.");
            continue;
        }
        if (action == 1) {
            rotateShape(&shapes[choice - 1]);
        } else if (action == 2) {
            flipShape(&shapes[choice - 1]);
        }
        if (checkShapeFit(&shapes[choice - 1], &silhouette)) {
            renderMessage("Shape fits the silhouette!");
            game_over = 1;  
        }
    }
    return 0;
}