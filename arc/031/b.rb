def dfs(xs, i, j)
  return if xs[i][j] == 'x'
  xs[i][j] = 'x'

  dfs(xs, i - 1, j) if i > 0
  dfs(xs, i + 1, j) if i < 9
  dfs(xs, i, j - 1) if j > 0
  dfs(xs, i, j + 1) if j < 9
end

def connect?(xs)
  count = 0
  10.times do |i|
    10.times do |j|
      count += 1 if xs[i][j] == 'o'
      dfs(xs, i, j)
    end
  end
  count == 1
end

xs = 10.times.map { gets.chomp }

ok = false
10.times do |i|
  10.times do |j|
    tmp = 10.times.map { |k| xs[k].dup }
    tmp[i][j] = 'o'

    ok |= connect?(tmp)
  end
end

puts ok ? :YES : :NO
