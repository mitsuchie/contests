A, B, C = gets.split.map(&:to_i)

ans = if (A + B == C) && (A - B == C)
        '?'
      elsif (A + B == C)
        '+'
      elsif (A - B == C)
        '-'
      else
        '!'
      end

puts ans
