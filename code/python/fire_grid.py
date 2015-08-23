import pygame; from pygame.locals import *
import random
import sys

WIDTH  = 500
HEIGHT = 500

screen = pygame.display.set_mode((WIDTH, HEIGHT))
screen.fill(pygame.Color('#fafdfe'))
pygame.display.set_caption('fire grid')

iterations = [
    [random.randrange(20, 25), random.randrange(20, 25)] # axiom
]

current_shade = (0, 0, 0)

def draw_matrix():
    for x in range(50):
        for y in range(50):
            pygame.draw.rect(
                screen,
                pygame.Color('#545557'),
                (x * 10, y * 10, 10, 10), # corner coords
                1 # do not fill the rectangle
            )
    pygame.display.flip()

def draw_node(x, y):
    global current_shade

    if current_shade[0] < 254:
        current_shade = (len(iterations), 0, 0)
    else:
        if current_shade[1] < 254:
            current_shade = (255, len(iterations) - 254, 0)
        else:
            current_shade = (255, 255, len(iterations) - 509)

    print current_shade

    pygame.draw.rect(
        screen,
        current_shade,
        (x * 10, y * 10, 10, 10),
        # give no 'width' argument so the shape is filled
    )
    pygame.display.flip()

def draw_crater(x, y):
    global iterations

    draw_node(x, y)

    # generate a maximum of 3 partners
    # in any of the 8 directions away from
    # the current node:
    partners = random.randrange(4)
    for i in range(partners):
        direction = random.choice(('n', 's', 'e', 'w',
                                   'ne', 'se', 'nw', 'sw'))
        if direction == 'n':
            if y == 1:
                iterations = []
            iterations.append([x, y - 1])
        elif direction == 's':
            if y == 49:
                iterations = []
            iterations.append([x, y + 1])
        elif direction == 'e':
            if x == 49:
                iterations = []
            iterations.append([x + 1, y])
        elif direction == 'w':
            if y == 1:
                iterations = []
            iterations.append([x - 1, y])
        elif direction == 'ne':
            if x == 49 or y == 1:
                iterations = []
            iterations.append([x + 1, y - 1])
        elif direction == 'se':
            if x == 49 or y == 49:
                iterations = []
            iterations.append([x + 1, y + 1])
        elif direction == 'nw':
            if x == 1 or y == 1:
                iterations = []
            iterations.append([x - 1, y - 1])
        elif direction == 'sw':
            if x == 1 or y == 49:
                iterations = []
            iterations.append([x - 1, y + 1])

# Use this if you want to have a grid
# showing all possible node positions:
# draw_matrix()

while 1:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            sys.exit(0)
        elif e.type == pygame.KEYDOWN:
            if e.key == K_j:
                for _ in range(15):
                    draw_crater(iterations[-1][0], iterations[-1][1])
            if e.key == K_ESCAPE:
                sys.exit(0)
