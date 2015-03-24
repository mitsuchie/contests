gets
xs = gets.split(' ').map(&:to_i).reject { |x| x == 0 }

sum = xs.reduce(&:+)
n   = xs.size
ans = sum % n == 0 ? sum / n : (sum / n) + 1

puts ans
