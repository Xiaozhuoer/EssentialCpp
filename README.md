
# 分支

+ vscode (default)  
+ vs2019  

# Test1.1  

将先前介绍的main()程序依样画葫芦地输入.

# Test1.5  

编写一个程序, 能够询问用户的姓名, 并读取用户所输入的内容. 请确保用户输入的名称长度大于两个字符. 如果用户的确输入了有效名称, 就响应一些信息. 请分别以C-Style字符串和String对象实现.

# Test1.6  

编写一个程序, 从标准输入设备读取一串整数, 并将读入的整数依次放到array及vector, 然后遍历这两种容器, 求取数值总和. 将总和及平均值输出至标准输出设备.

# Test1.7  

输入两行文字并存盘. 然后编写一个程序, 打开该文本文件, 将其中的每个字都读取到一个vector\<string>对象中. 遍历该vector, 将内容显示到cout. 然后利用泛型算法sort(), 对所有文字排序:

    \#include \<algorithm>  
    sort( container.begin(), container.end());  

再将排序后的结果输出到另一个文件.

# Test1.8  

1.4节的switch语句让我们得以根据用户答错的次数提供不同的安慰语句. 请以array储存四种不同的字符串信息, 并以用户答错次数作为array的索引值, 以此方式来显示安慰语句.  

# Test2.1  

先前的main()只让用户输入一个位置值, 然后便结束程序. 如果用户想取得两个甚至更多元素值, 他必须执行这个程序两次或多次. 请该写main(), 使它允许用户不断输入位置值, 直到用户希望停止为止.  

# Test2.2  

Pentagonal数列的求值公式是P(n)=n(3n-1)/2, 借此产生1,5,12,22,35等元素值, 试定义一个函数, 利用上述公式, 将产生的元素放到用户传入的vector之中, 元素由用户指定. 请检查元素个数的有效性 (太大则可能引发overflow问题). 接下来编写第二个函数, 能够将给定的vector的所有元素一一打印. 此函数的第二个参数接受一个字符串, 表示存放在vector内的数列的类型, 最后再写一个main(), 测试上述两个函数.  

# Test2.3  

将练习2.2的Pentagonal数列求值函数拆分为两个函数, 其中之一为inline, 用来检验元素个数是否合理. 如果的确合理, 而且尚未被计算, 便执行第二个函数, 执行实际的求值工作.  

# Test2.4  

写一个函数, 以局部静态(local static)的vector储存Pentagonal数列元素. 此函数返回一个const指针, 指向该vector. 如果vector的大小小于指定的元素个数, 就扩充vector的大小. 接下来再实现第二个函数, 接受一个位置值, 返回该位置上的元素. 最后, 编写main()测试这些函数.  

# Test2.5  

实现一个重载的max()函数, 让它接受以下参数:  

1. 两个整数
2. 两个浮点数
3. 两个字符串
4. 一个整数vector
5. 一个浮点数vector
6. 一个字符串vector
7. 一个整数数组, 以及一个表示数组大小的整数值
8. 一个浮点数数组, 以及一个表示数组大小的整数值
9. 一个字符串数组, 以及一个表示数组大小的整数值

最后, 编写main()测试这些函数.  

# Test2.6

以template重新完成练习2.5, 并对main()函数做适度的修改.  
