const M : usize = 1_000_000_007;

fn main()
{
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();

    let data: Vec<&str> = line.split_whitespace().collect();
    let r1 = data[0].parse().unwrap_or(0);
    let c1 = data[1].parse().unwrap_or(0);
    let r2 = data[2].parse().unwrap_or(0);
    let c2 = data[3].parse().unwrap_or(0);

    let n = r2 + c2 + 2;

    let mut f1 = vec![1; n];
    let mut f2 = vec![1; n];
    let mut ff = vec![1; n];

    for i in 2..n
    {
        f1[i]  = f1[i - 1] * i % M;
        ff[i] = M - ff[M % i] * (M / i) % M;
        f2[i] = f2[i - 1] * ff[i] % M;
    }

    let ncr = |n, r| (f1[n] * ((f2[r] * f2[n - r]) % M)) % M;
    let sum = |x, y| (1 .. (x + 2)).fold(0, |v, i| (v + ncr(y + i, i)) % M);

    let a = sum(r2, c2);
    let b = sum(r1 - 1, c2);
    let c = sum(r2, c1 - 1);
    let d = sum(r1 - 1, c1 - 1);

    let ans = (4 * M + a + d - b - c) % M;
    println!("{}", ans);
}
