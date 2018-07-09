#include <stdio.h>


int a[10], book[10], n;
// C 语言的全局变量在没有赋值以前默认为0，因此这里的 book 数组无需再次赋值为0

void dfs(int step) 
{
    int i;
    // 如果站在第 n + 1个盒子面前，则表示前 n 个盒子已经放好扑克牌
    if (step == n + 1)
    {
        
        // 输出一种排列(1~n号盒子中的扑克牌编号)
        for(i = 0; i <= n; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
        // 返回之前的一步（最近一次调用 dfs 函数的地方）
        return;
    }

    // 此时站在第 step 个盒子面前，应该放哪张牌呢？
    // 按照1、2、3...n 的顺序一一尝试
    
    for(i = 0; i <= n; i++)
    {
        // 判断扑克牌 i 是否还在手上
        // book[i] == 0  表示 i 号扑克牌还在手上
        if (book[i] == 0) {
            // 开始尝试使用扑克牌 i
            // 将 i 号扑克牌放入到第 step 个盒子中
            a[step] = i;
            // 将 book[i]设为1，表示 i 号扑克已经不在手上
            book[i] = 1;
            // 第 step 个盒子已经放好扑克牌，接下来需要走到下一个盒子面前

            dfs(step + 1);
            // 这是非常重要的一步，一定要将刚才尝试的扑克牌收回，才能进行下一步尝试
            book[i] = 0;
        }
        
    }
    return;
    
}

int main()
{
    // 输入的时候注意n 为1~9之间的整数
    scanf("%d", &n);
    // 首先站在1号小盒子的面前
    dfs(1);
    getchar();getchar();
    return 0;
}

