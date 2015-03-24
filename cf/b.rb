N, K = STDIN.gets.split(' ').map(&:to_i)

sum = 0
N.times do |i|
  sum += STDIN.gets.to_i
  next if sum < K

  puts i + 1
  break
end
