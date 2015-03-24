N = STDIN.gets.to_i
hs1 = N.times.map { STDIN.gets.to_i }
hs2 = hs1.reverse
hs1 << 10_000_000
hs2 << 10_000_000

dp1 = (N + 1).times.to_a.map(&1.method(:+))
dp2 = (N + 1).times.to_a.map(&1.method(:+))

(N - 1).downto(0) { |i| dp1[i] = dp1[dp1[i]] while hs1[i] >= hs1[dp1[i]] }
(N - 1).downto(0) { |i| dp2[i] = dp2[dp2[i]] while hs2[i] >= hs2[dp2[i]] }
(N - 1).downto(0) { |i| dp1[i] -= i + 1 }
(N - 1).downto(0) { |i| dp2[i] -= i + 1 }

dp1.pop
dp2.pop
dp2.reverse!

N.times.map { |i| dp1[i] + dp2[i] }.each(&method(:puts))
