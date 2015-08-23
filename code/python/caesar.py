import sys

alphabet = "abcdefghijklmnopqrstuvwxyz"
ciphered = ""

for l in sys.argv[1]:
    if l in alphabet:
        ciphered += alphabet[26 - alphabet.index(l)]
    else:
        ciphered += l

print ciphered
