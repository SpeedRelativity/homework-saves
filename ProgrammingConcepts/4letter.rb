
dict_path = "dictionary.txt"


dict = File.read(dict_path).split

# puts dict


# sample selects 4 random items from dict. No need for rand() like in C++
chosen = dict.sample(4)

# iterate over chosen words and print it out
# chosen.each do |word|
#   # puts word
# end

grid = chosen.join
grid = grid.chars
puts grid[0,16].join(' ')
grid.shuffle!


# 4 times we will print a grid [4x4 matrix] and a space between.
4.times do |i|
  puts grid[i*4,4].join(' ') # 0 - 4, 4 - 8, it is printing words [start_index, length]
end


correct = 0


# main loop. 3 attempts, 4 words, 4 prompts.

3.times do |attempt|
  puts "Attempt #{attempt + 1}"
  
  4.times do 
    puts "Enter a 4-letter word:"
    input = gets.chomp
    
    if chosen.include?(input)
      puts "Valid word!"
      correct += 1
    else
      puts "You said #{input}"
      puts "Invalid word!"
    end
  end
  
  if correct == 4 
    puts "You win!"
    break
  elsif attempt == 2
    puts "You lose!"
    break
  end
end

  





