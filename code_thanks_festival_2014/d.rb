N, Q = gets.split.map(&:to_i)

Q.times do
  a, b, s, t = gets.split.map(&:to_i)
  aa = [a, b].min
  bb = [a, b].max
  ss = [s, t].min
  tt = [s, t].max

  x = if aa <= ss && tt <= bb
        0
      elsif ss <= aa && aa <= tt && tt < bb
        aa - ss
      elsif ss <= bb && bb <= tt && aa < ss
        tt - bb
      elsif ss <= aa && aa <= tt && ss <= bb && bb <= tt
        (tt - ss) - (bb - aa)
      else
        tt - ss
      end

  puts x * 100
end
