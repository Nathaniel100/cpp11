#include <iostream>
/* *
 * Syntax
 * [capture-list] (params) mutable(optional) exception attribute -> ret {body}
 * [capture-list] (params) -> ret {body}
 * [capture-list] (params) {body}
 * [capture-list] {body}
 *
 * */
int main() {
    auto glambda = [](auto a, auto &&b) {return a < b;};
    bool b = glambda(3, 3.14);
    auto vglambda = [](auto printer) {
        return [=](auto &&... ts) {
            printer(std::forward<decltype(ts)> (ts)...);
            return [=]{printer(ts...);};
        };
    };
    auto p = vglambda([](auto v1, auto v2, auto v3) {std::cout << v1 << v2 << v3;});
    auto q = p(1, 'a', 3.14);
    q();
    return 0;
}
