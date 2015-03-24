scores = 3.times.map { gets.to_i }
puts scores.map {|score| scores.reject {|s| s < score }.size }

# p 3.times.map {|i| [gets.to_i, i + 1] }.sort_by(&:first).reverse#.map(&:last)
