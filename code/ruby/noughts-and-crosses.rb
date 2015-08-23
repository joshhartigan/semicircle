class Game
  def initialize
    # The board is a string of bits, 0 [noughts] or 1 [crosses]
    @board = "_________"
  end

  WIN_PATTERNS = [
    '111000000', '000111000', '000000111',
    '100100100', '010010010', '001001001',
    '100010001', '001010100'
  ]

  def to_s
    @board.gsub('0', 'o').gsub('1', 'x').scan(/.{3}/)
  end

  def set_piece(pos, piece)
    if piece == 'x'
      @board[pos] = '1'
    elsif piece == 'o'
      @board[pos] = '0'
    else
      $stderr.puts "set_piece: Invalid piece #{piece}."
    end
  end

  def get_piece(pos)
    @board[pos]
  end

  def winner
    WIN_PATTERNS.each do |pattern|
      if @board == pattern
        "x"
      elsif @board.tr("01","10") == pattern
        "o"
      end
    end
  end

  def turn(player)
    print 'position? [0-9] '
    position = gets.chomp.to_i
    while get_piece(position) != '_'
      position = gets.chomp.to_i
    end
    set_piece(position, player)
  end
end

my_game = Game.new
puts my_game.to_s
my_game.turn 'x'
my_game.turn 'o'
puts my_game.to_s
