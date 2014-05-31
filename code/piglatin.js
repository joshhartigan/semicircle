function pigl(word) {
    if ("aeiou".indexOf(word.charAt(0)) > -1) {
        return word + "ay";
    } else {
        return word.slice(1) + word.charAt(0) + "ay";
    }
}

function pigLatinTranslate(text) {
    var words = text.split(" ");
    var translated = "";
    for (var i = 0; i < words.length; i++) {
        translated += pigl(words[i]) + " ";
    }
    return translated;
}
