import pygame
import random
import sys

from pygame.locals import *

WIDTH = 500
HEIGHT = 500

screen = pygame.display.set_mode((WIDTH, HEIGHT))
screen.fill(pygame.Color("#e8e8e8"))
pygame.display.set_caption("icogen")

def draw_icon(r, g, b):
  for x in range(5):
    for y in range(5):
      red = random.randrange(r)
      green = random.randrange(g)
      blue = random.randrange(b)
      pygame.draw.rect(screen, (red, green, blue), (x*100, y*100, 100, 100))
  pygame.display.flip()

while True:
  for e in pygame.event.get():
    if e.type == pygame.QUIT:
      sys.exit(0)
    elif e.type == pygame.KEYDOWN:
      if e.key == K_j:
        draw_icon(255, 200, 155)
