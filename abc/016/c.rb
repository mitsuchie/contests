N, M = gets.split.map(&:to_i)
INF = 10**9

@dist = Array.new(N).map { Array.new(N) }
N.times { |i| N.times { |j| @dist[i][j] = INF } }

M.times do
  a, b = gets.split.map(&:to_i).map { |x| x - 1 }
  @dist[a][b] = 1
  @dist[b][a] = 1
end


N.times do |i|
  N.times do |j|
    N.times do |k|
      @dist[i][j] = [@dist[i][j], @dist[i][k] + @dist[k][j]].min
    end
  end
end


N.times do |i|
  @dist[i][i] = INF
  puts @dist[i].reject { |x| x == 1 || x == INF }.size
end
