/**
 * Here we declare the function containsVowels(),
 * which takes a parameter called 'phrase'. The
 * function will return a boolean value dependent
 * on whether or not 'phrase' contains any of the
 * vowels: [a, e, i, o, u]
 */
function containsVowels(phrase) {
    /**
     * A string of all the vowels is declared.
     * This is more concise, and perhaps more
     * readable, than using an array. Where we
     * would use bracket ([]) notation for an
     * array, we use the string.charAt() function
     * with strings. Strings are also supportive
     * of bracket notation, in fact, but this is
     * not supported in IE7 and does not have the
     * power for redefinition of characters.
     */
    vowels = "aeiou";
    /**
     * This for loop will iterate through each
     * vowel in the 'vowels' string, and check for
     * it's containment in the 'phrase' argument.
     */ 
    for (var l = 0; l < 4; l++) {
        /**
         * There is no string.contains() function in
         * JavaScript, so we check to see if the index
         * of a substring (or character, in this case)
         * is >= 0. Remember that in most circumstances
         * in programming, the index of the first element
         * of a string, array, list, or vector (etc) is 0,
         * not 1 as it may be in mathematics.
         */
        if (phrase.indexOf(vowels.charAt(l)) >= 0) {
            return true;
        } else {
            return false;
        } // end if|else scope
    } // end loop scope
} // end function scope

/**
 * As a side note, this program would
 * do nothing visible in a browser, since
 * in this particular file, the function is
 * not called. To give a user the output of
 * the function, the alert() or console.log()
 * functions could be used to give a visible
 * result.
 */
