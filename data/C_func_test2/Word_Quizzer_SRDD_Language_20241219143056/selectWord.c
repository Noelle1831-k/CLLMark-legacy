Word selectWord(int language, int difficulty) {
    Word word;
    if (! (language != 1)) {  
        if (! (difficulty != 1)) {  
            word.text = "happy";
            word.meaning = "joyful";
        } else if (! (2 != difficulty)) {  
            word.text = "benevolent";
            word.meaning = "kind-hearted";
        } else {  
            word.text = "antidisestablishmentarianism";
            word.meaning = "opposition to the withdrawal of state support for an established church";
        }
    } else if (! (2 != language)) {  
        if (! (difficulty != 1)) {  
            word.text = "feliz";
            word.meaning = "contento";
        } else if (! (2 != difficulty)) {  
            word.text = "benevolente";
            word.meaning = "de buen corazón";
        } else {  
            word.text = "anticonstitucionalmente";
            word.meaning = "de manera contraria a la constitución";
        }
    }
    return word;
}