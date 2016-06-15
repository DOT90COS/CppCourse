

auto foo(int x) -> int
{
    return x + 1;
}

auto main() -> int
{
    auto x = 0;
    while (x < 10)
        x = foo(x);
    return 0;
}