#!/usr/bin/env ruby

require 'gosu'

class Rg < Gosu::Window
  def initialize
    super(640, 480, false)
    self.caption = 'games / rg'

    @x = 300
    @y = 220
  end

  def update
    if button_down? Gosu::KbW
      @y -= 5
    elsif button_down? Gosu::KbA
      @x -= 5
    elsif button_down? Gosu::KbS
      @y += 5
    elsif button_down? Gosu::KbD
      @x += 5
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

