__author__ = "Josh Hartigan"

# www.coderbyte.com is a website I found that contains
# various programming challenges of different difficulties.
# this file holds some of my solutions to the challenges.
# If you're doing the coderbyte challenges yourself, don't
# straight up copy my answers for yourself. There are probably
# more efficient ways to do them, and you won't learn anything.

def powers_of_two(num):
    """ Determine whether or not 'num' is a power of two. """
    for i in range(num):
        if 2**i == num:
            return "true"
    return "false"

def longest_word(sentence):
    """ Return the longest word (without punctuation) in a string of multiple words. """
    punctuation = ("?","!",":","?","/","\\","\"","£","$","%","^","&","*","(",")",
                   "-","_","+","=","[","]","{","}","@","|")
    longest = ""

    for word in sentence.split(" "):
        without_punctuation = "".join(c for c in word if c not in punctuation)
        if len(without_punctuation) > len(longest):
            longest = without_punctuation
    return longest

def x_o(string):
    """ Determine whether the number of 'x's in a string is the same as the number of 'o's. """
    if string.count("x") == string.count("o"):
        return True
    else:
        return False

def simple_adding(num):
    """ Add up all the numbers from 1 to num. """
    return sum(range(num + 1))

def letter_capitalize(string):
    """ Capitalize the first letter of each word in a string.
        My version here also removes numbers. """
    return "".join([i for i in string if not i.isdigit()]).title()

