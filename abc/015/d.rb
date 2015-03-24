W = gets.to_i
N, K = gets.split(' ').map(&:to_i)
AB = N.times.map { gets.split(' ').map(&:to_i) }

@dp = [[[-1] * 10_001] * 51] * 51

def dfs(n, m, l)
  return 0 if n == N
  return @dp[n][m][l] if @dp[n][m][l] != -1

  a, b = [0, 0]
  a = dfs(n + 1, m, l)
  b = dfs(n + 1, m + 1, l - AB[n][0]) + AB[n][1] if l >= AB[n][0] && m + 1 <= K

  @dp[n][m][l] = [a, b].max
end

puts dfs(0, 0, W)
