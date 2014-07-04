import praw
import sys

user_agent = ("Simple CLI for Reddit by /u/peridox"
              "github.com/joshhartigan/semicircle")
reddit = praw.Reddit(user_agent)

if len(sys.argv) == 3:
  subreddit = sys.argv[1]
  postNumber = sys.argv[2]
else:
  print "*** ReddiTerm - Usage: `python redditerm.py <subreddit> <postCount>"
try:
  postNumber = int(postNumber)
except ValueError:
  print "*** ReddiTerm - Invalid post number."
  sys.exit(1)

posts = reddit.get_subreddit(subreddit).get_top(limit=postNumber)

print "ReddiTerm in /r/" + subreddit + ":"
print "Press return to iterate through, posts, type 'q<RET>' to quit."

command = raw_input(": ")
while command != "q":
  try:
    post = next(posts)
  except StopIteration:
    print "*** ReddiTerm - Quitting."
    sys.exit(0)
  print "\"" + post.title + "\" - " + str(post.score)
  print "\t[" + post.url + "]"
  command = raw_input(": ")

print "*** ReddiTerm - Quitting."
