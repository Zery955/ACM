#include<ext/rope>

using namespace __gnu_cxx;  // 注意名称空间

rope<int> rp;

int main() {

    rp.push_back(x); // 在末尾插入 x

    rp.insert(pos, x); // 在 pos 处插入 x

    rp.erase(pos, x); // 在 pos 处删除 x 个元素

    rp.length(); // 返回 rp 的大小

    rp.size(); // 同上

    rp.replace(pos, x); // 将 pos 处的元素替换成 x

    rp.substr(pos, x); // 从 pos 处开始提取 x 个元素

    rp.copy(pos, x, s); // 从 pos 处开始复制 x 个元素到 s 中

    rp[x]; // 访问第 x 个元素

    rp.at(x); // 同上

    return 0;
}