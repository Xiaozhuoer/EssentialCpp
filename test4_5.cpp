/*
--------------------------------------------------------

	请实现一个4x4的 Matrix Class, 至少提供一下接口: 矩阵加法, 矩阵乘法, 打印函数print(), 复合运算符+=,
	以及一组支持下标操作的function call运算符, 像下面这样:  
		float& operator() (int row, int column );  
		float  operator() (int row, int column ) const;
	请提供一个 default constructor, 可选择性地接受16个数据值. 再提供一个constructor(构造函数), 可接受一个拥有16个元素的数组. 你不需要为此 class 提供 copy constructor, copy assignment operator, destructor.  

--------------------------------------------------------
*/
//目前只能用MSVC编译
#include <iostream>
#include <array>
#include "test4_5_Matrix.h"

int main() 
{
	Matrix m;
	std::cout << m << std::endl;

	float ar1[16] = { 1., 2., 3., 4., 5., 6., 7., 8.,
					 1., 2., 3., 4., 5., 6., 7., 8. };

	Matrix m1(ar1);
	std::cout << m1 << std::endl;
	
	Matrix m2(ar1);
	Matrix m3 = m1 * m2;
	std::cout << m3 << std::endl;

	return 0;
}