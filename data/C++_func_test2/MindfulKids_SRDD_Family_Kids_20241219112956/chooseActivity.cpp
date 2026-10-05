void chooseActivity(int choice) {
        switch (choice) {
            case 1: {
                MindfulnessSession meditationSession;
                meditationSession.startSession("Guided Meditation");
                break;
            }
            case 2: {
                MindfulnessSession breathingExercise;
                breathingExercise.guideBreathingExercise();
                break;
            }
            case 3: {
                Game* game = new Game();
                game->startGame();
                delete game;
                break;
            }
            case 4: {
                Puzzle puzzle;
                puzzle.startPuzzle();
                break;
            }
            case 5: {
                Journal journal;
                journal.writeJournalEntry();
                journal.viewJournalEntries();
                break;
            }
            case 6: {
                ColoringBook coloringBook;
                coloringBook.displayPage();
                coloringBook.chooseColors();
                break;
            }
            case 0:
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    }