import sys

filename = sys.argv[1]

markdown = open(filename, "r+")

if ".md" in filename:
    filename = filename.replace("md", "html")
elif ".markdown" in filename:
    filename = filename.replace("markdown", "html")
else:
    print "Incorrect filetype"
    sys.exit(0)

# to prevent bugs, append a space to md file
# markdown.write(" ")

# html boilerplate + sans font -------------------------------------------
html = open(filename, 'w')
html.write("<!doctype html>\n")
html.write("<html>\n")
html.write("<head>\n")
html.write(     "\t<title>" + filename.replace(".html","") + "</title>\n")
html.write(     "\t<style>\n")
html.write(         "\thtml { font-family: sans-serif; }\n")
html.write(     "\t</style>\n")
html.write("</head>\n<body>\n")
#-------------------------------------------------------------------------

previousLine = markdown.readline()
for line in markdown:
    words = line.split(" ")

    # generate header
    if line[0] == "=" and line.strip() == len(line.strip()) * "=":
        html.write("<h1>" + previousLine.strip() + "</h1>\n")
    previousLine = line
    
    for word in words:
        noDot = word.replace(".","")

        if len(word) > 0:
            # generate italics
            if word[0] == "*" and word[1] != "*" and noDot[len(noDot.strip()) - 1] == "*":
                html.write("<em>" + word.strip().replace("*","") + "</em> ")
            elif word[0:2] == "**" and noDot[len(noDot)-2:len(noDot)] == "**":
                html.write("<strong>" + word.strip().replace("**","") +
                "</strong> ")
            else:
                if word.strip() != len(word.strip()) * "=":
                    html.write(word.strip() + " ")

html.write("\n</body>\n</html>")
