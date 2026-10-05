void displayMenu() {
        int choice;
        do {
            cout << "Welcome to FamilyCookingTime!" << endl;
            cout << "1. View Recipes" << endl;
            cout << "2. Add Recipe to Favorites" << endl;
            cout << "3. View Grocery List" << endl;
            cout << "4. Start Cooking Timer" << endl;
            cout << "5. Ingredient Substitution" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    viewRecipes();
                    break;
                case 2:
                    addRecipeToFavorites();
                    break;
                case 3:
                    viewGroceryList();
                    break;
                case 4:
                    startCookingTimer();
                    break;
                case 5:
                    ingredientSubstitutionMenu();
                    break;
                case 6:
                    cout << "Exiting application. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice, try again!" << endl;
            }
        } while (choice != 6);
    }