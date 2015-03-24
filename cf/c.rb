A = STDIN.gets.chomp.chars.sort.join
B = STDIN.gets.chomp.chars.sort.join
C = STDIN.gets.chomp.chars.sort.join

puts A
puts B
puts C

N = A.size / 2

ok = false
(A.size - N).times do |i|
  (B.size - N).times do |j|
    s = (A[i..(i + N - 1)] + B[j..(j + N - 1)]).chars.sort.join
    puts "#{i},#{j}: #{s}"
    ok = true && break if s == C
  end
end

puts ok ? :YES : :NO
