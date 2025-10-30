
dict_path = "dictionary.txt"


dict = File.read(dict_path).split

puts dict


# sample selects 4 random items from dict. No need for rand() like in C++
chosen = dict.sample(4)

# iterate over chosen words and print it out
chosen.each do |word|
  # puts word
end

grid = chosen.join
grid = grid.chars
grid.shuffle!


# 4 times we will print a grid [4x4 matrix] and a space between.
4.times do |i|
  puts grid[i*4,4].join(' ') # 0 - 4, 4 - 8, it is printing words [start_index, length]
end


3.times do |attempt|
  puts "Attempt #{attempt + 1}"

  correct = 0 

  





