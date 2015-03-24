N, M, K = gets.split.map(&:to_i)
CS = gets.split

@connects = [[]] * N
M.times.each do
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  @connects[a] += [b]
end

def dfs(pos, visited)
  # return '' unless visited[pos].nil?
  visited[pos] = true

  res = [CS[pos]]
  @connects[pos].select { |i| visited[i].nil? }.each { |i| res << dfs(i, visited) }
  res
end

p N.times.map { |i| dfs(i, {}).join }
