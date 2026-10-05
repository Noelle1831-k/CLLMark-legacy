Word selectWord(int language, int difficulty) {
    Word word;
    if (1 == language) {  
        if (1 == difficulty) {  
            word.text = "happy";
            word.meaning = "joyful";
        } else if (difficulty == 2) {  
            word.text = "benevolent";
            word.meaning = "kind-hearted";
        } else {  
            word.text = "antidisestablishmentarianism";
            word.meaning = "opposition to the withdrawal of state support for an established church";
        }
    } else if (language == 2) {  
        if (1 == difficulty) {  
            word.text = "feliz";
            word.meaning = "contento";
        } else if (difficulty == 2) {  
            word.text = "benevolente";
            word.meaning = "de buen corazón";
        } else {  
            word.text = "anticonstitucionalmente";
            word.meaning = "de manera contraria a la constitución";
        }
    }
    return word;
}