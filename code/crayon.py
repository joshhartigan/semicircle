import pygame
from pygame.locals import *

import random
import sys

WHITE = (255, 255, 255)
BLACK = (  0,   0,   0)

DISPLAY = (640, 480)
screen = pygame.display.set_mode(DISPLAY)
screen.fill(WHITE)
pygame.display.flip()

class FloatingTile:
    def __init__(self, colour, x, y):
        self.colour = colour
        
        self.xvel = random.randrange(-3, 3)
        self.yvel = random.randrange(-3, 3)
    
        self.rect = pygame.Rect(x, y, 20, 20)
    def collide(self):
        """ collide tile with edges of screen """
        if self.rect.left < 0 or self.rect.right > 640:
            self.xvel = -self.xvel + (random.randrange(-3, 3) * random.randrange(-1, 1))
        if self.rect.top < 0 or self.rect.bottom > 480:
            self.yvel = -self.yvel + (random.randrange(-3, 3) * random.randrange(-1, 1))
    def draw(self):
        """ draw tile to screen with size 20 and random colour """
        red = random.randrange(255)
        green = random.randrange(255)
        blue = random.randrange(255)
        pygame.draw.rect(screen, (red, green, blue), self.rect)
        pygame.display.flip()
    def erase(self):
        """ draw white version of tile """
        pygame.draw.rect(screen, WHITE, self.rect)
        pygame.display.flip()
    def move(self):
        """ move tile via x and y velocity """
        self.rect.move_ip((self.xvel, self.yvel))

tile = FloatingTile(BLACK, 320, 240)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit(0)
        if event.type == pygame.KEYDOWN:
            if event.key == K_ESCAPE:
                sys.exit(0)
    tile.draw()
    tile.move()
    tile.collide()
