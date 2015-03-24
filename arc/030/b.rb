N, X = gets.split.map(&:to_i)
HS = gets.split.map(&:to_i)

@connects = [[]] * N

(N - 1).times.each do
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  @connects[a] += [b]
  @connects[b] += [a]
end

def dfs(pos, visited)
  visited[pos] = true

  res = [0, 0]
  @connects[pos].select { |i| visited[i].nil? }.each do |i|
    juels, costs = dfs(i, visited)
    next if juels == 0

    res[0] += juels
    res[1] += costs
  end
  res[0] += HS[pos]
  res[1] += 2 if res[0] != 0
  res
end

puts [dfs(X - 1, {})[1]  - 2, 0].max
