void customizeReadingExperience(User &user, string fontSize, string bgColor) {
        user.setPreferences("FontSize", fontSize);
        user.setPreferences("BackgroundColor", bgColor);
    }