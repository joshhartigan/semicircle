import pygame
import random
import sys
import time

screen = pygame.display.set_mode( (640, 480) )
pygame.display.set_caption('opposite colors')

r = lambda limit: random.randint(0, limit)

def draw():
  color = '%02X%02X%02X' % ( r(255), r(255), r(255) )
  pygame.draw.rect( screen, pygame.Color('#' + color),
                    (0, 0, 320, 480) )
  pygame.draw.rect( screen, pygame.Color('#' + color[::-1]),
                    (320, 0, 320, 480) )
  pygame.display.flip()

while True:
  draw()
  time.sleep(2)
  for e in pygame.event.get():
    if e.type == pygame.QUIT:
      sys.exit(0)
