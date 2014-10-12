class Greeter
  def initialize(name = "Josh")
    @name = name
  end

  def greet
    puts "hello, #{@name}"
  end

  def farewell
    puts "goodbye, #{@name}"
  end
end

greeter = Greeter.new("Esbjorn")
greeter.greet
greeter.farewell

