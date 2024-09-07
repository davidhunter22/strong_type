import strong_type;

import std;

int main( )
{
    using type = strong::type<std::string, struct i_, strong::equality>;

    type i { "Hello" };

    return 0;
}