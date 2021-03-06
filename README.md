
# 分支

+ vscode (default)  
+ vs2019  

# bubblesort  

BubbleSort冒泡排序算法

# fstream  

简单的文件读写练习

# GenericAlgorithm  

2020.11.1 : 难!
2020.11.2 ：BUG修改完成！

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

# Test3.1  

写一个读取文本文件的程序, 将文件中的每个单字存入map. map的key便是刚才所说的单字, map的value则是该单字在文本文件中的出现次数. 再定义一份由“排除字眼”组成的set, 其中包含诸如a, an, or, the, and和but之类的单字. 将某单字放入map之前, 先确定该单字并不在“排除子集”中. 一旦文本文件读取完毕, 请显示一份单字清单, 并显示各单字的出现次数. 你甚至可以再加以扩展, 在显示单字之前, 允许用户查询某个单字是否出现于文本文件中.  

# Test3.2  

读取文本文件内容---和练习3.1一样---并将内容存储于vector. 以字符串长度为依据, 对vector排序. 定义一个function object并传给sort(); 将一function object接受两个字符串, 当第一字符串的长度小于第二字符串的长度时, 就返回true. 最后, 打印排序后的vector内容.  

# Test3.3  

定义一个map, 以家庭姓氏为key, value则是家庭所有小孩的名字. 令此map至少容纳六笔数据. 允许用户根据姓氏来查询, 并得以打印map内的每一笔数据.  

# Test3.4  

编写一个程序, 利用istream_iterator从标准输入设备读取一连串整数. 利用ostream_iterator将其中的奇数写至某个文件, 每个数值皆以空格分隔. 再利用ostream_iterator将偶数写到另一个文件, 每个数值单独放在一行中.  

# Test4.1  

建立Stack.h, 编写main()函数, 练习操作Stack的所有公开接口, 并加以编译执行. 程序代码文件和main()都必须包含Stack.h:  
    #include "Stack.h"  

# Test4.2  

扩展Stack的功能, 以支持find()和count()两个操作.find()会查看某值是否存在而返回true或false. count()返回某字符串的出现次数.  

# Test4.3  

考虑以下所定义的全局(global)数据:  

+ string program_name;
+ string version_stamp;
+ int version_number;
+ int tests_run;
+ int tests_passed;  

编写一个包装这些数据的类.  

# Test4.4  

一份"用户概况记录(user profile)" 内含以下数据: 登录记录, 实际姓名, 登入次数, 猜过次数, 猜对次数, 等级——包括初级, 中级, 高级, 专家, 以及猜对百分比(可实时计算获得, 或将其值储存起来备用). 请写出一个名为UserProfile的class,　提供以下操作: 输入, 输出, 相等测试, 不等测试.其constructorb必须能够处理默认的用户等级, 默认的登录名称("guest"). 对于同样名为guest的多个用户, 你如何保证每个guest有他自己独有的登录会话(login session), 不会和其他人混淆?  

# Test4.5  

请实现一个4x4的 Matrix Class, 至少提供一下接口: 矩阵加法, 矩阵乘法, 打印函数print(), 复合运算符+=,
以及一组支持下标操作的function call运算符, 像下面这样:  

+ float& operator() (int row, int column );  
+ float  operator() (int row, int column ) const;

请提供一个 default constructor, 可选择性地接受16个数据值. 再提供一个constructor(构造函数), 可接受一个拥有16个元素的数组. 你不需要为此 class 提供 copy constructor, copy assignment operator, destructor.  
