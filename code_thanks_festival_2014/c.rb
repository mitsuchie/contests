N, M = gets.split.map(&:to_i)
PS = gets.split.map(&:to_i)
SS = gets.split.map(&:to_i)

puts SS.map { |x| PS[x - 1] }.reduce(:+)
