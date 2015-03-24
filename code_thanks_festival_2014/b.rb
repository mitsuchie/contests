N = gets.to_i
xs = 3.times.map { gets.to_i }
xs = xs.sort.reverse
ds = [0, 0, 0]

n = 0
turn = 0

while n < N
  turn = turn + 1
  ds = ds.map { |d| [d-1, 0].max }

  if ds[0] == 0
    ds[0] = 3
    n += xs[0]
  elsif ds[1] == 0
    ds[1] = 3
    n += xs[1]
  elsif ds[2] == 0
    ds[2] = 3
    n += xs[2]
  end
end

puts turn
