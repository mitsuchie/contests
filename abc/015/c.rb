N, K = gets.split(' ').map(&:to_i)
T = N.times.map { gets.split(' ').map(&:to_i) }

def dfs(depth, xor)
  return xor == 0 if depth == N
  T[depth].map { |t| dfs(depth + 1, xor ^ t) }.reduce(&:|)
end

puts dfs(0, 0) ? :Found : :Nothing
