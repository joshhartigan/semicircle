#!/usr/bin/env ruby

require 'gosu'

class Rg < Gosu::Window
  WIDTH = 640
  HEIGHT = 480

  def initialize
    super(WIDTH, HEIGHT, false)
    self.caption = 'games / rg'

    @x = (WIDTH / 2) - 20
    @y = (HEIGHT / 2) - 20
  end

  def update
    if button_down? Gosu::KbW
      if @y >= 20 then @y -= 5 end
    elsif button_down? Gosu::KbA
      if @x >= 0 then @x -= 5 end
    elsif button_down? Gosu::KbS
      if @y <= (HEIGHT - 20) then @y += 5 end
    elsif button_down? Gosu::KbD
      if @x <= (WIDTH - 20) then @x += 5 end
    end
  end

  def draw
    draw_rect self, @x, @y, 20, 20, Gosu::Color::argb(0xffabcdef)
  end
end

def draw_rect(rg, x, y, width, height, color)
  rg.draw_quad(x, y, color,
               x + width, y, color,
               x, y + height, color,
               x + width, y + height, color)
end

game = Rg.new
game.show

