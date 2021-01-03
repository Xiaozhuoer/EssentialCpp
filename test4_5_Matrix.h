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

typedef float elemType;

class Matrix {

public:

	Matrix( elemType = 0., elemType = 0., elemType = 0., elemType = 0., 
		    elemType = 0., elemType = 0., elemType = 0., elemType = 0., 
			elemType = 0., elemType = 0., elemType = 0., elemType = 0., 
			elemType = 0., elemType = 0., elemType = 0., elemType = 0. ); //可选择性地接受16个数据值
	Matrix( const elemType *);//接受一个拥有16个元素的数组
	std::ostream& print(std::ostream&) const; //打印数组
	elemType operator()(int row, int col) const { return _Matrix[row][col]; }//获取数组[x][y]的值
	elemType& operator()(int row, int col) { return _Matrix[row][col]; }//赋值数组[x][y]的值

	void operator+=(const Matrix&);//重写复合运算符+=

private:

	elemType _Matrix[4][4];

};

//构造函数: 可选择性地接受16个数据值
Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14, 
			   elemType a21, elemType a22, elemType a23, elemType a24, 
	           elemType a31, elemType a32, elemType a33, elemType a34,
	           elemType a41, elemType a42, elemType a43, elemType a44)
{
	_Matrix[0][0] = a11;	_Matrix[0][1] = a12;	_Matrix[0][2] = a13;	_Matrix[0][3] = a14;
	_Matrix[1][0] = a21;	_Matrix[1][1] = a22;	_Matrix[1][2] = a23;	_Matrix[1][3] = a24;
	_Matrix[2][0] = a31;	_Matrix[2][1] = a32;	_Matrix[2][2] = a33;	_Matrix[2][3] = a34;
	_Matrix[3][0] = a41;	_Matrix[3][1] = a42;	_Matrix[3][2] = a43;	_Matrix[3][3] = a44;
}

//构造函数: 接受一个拥有16个元素的数组
inline Matrix::Matrix(const elemType *array )
{
	int array_index = 0;
	for (int x = 0; x < 4; x++) 
		for (int y = 0; y < 4; y++, array_index++) 
			_Matrix[x][y] = array[array_index];
}

//重写操作符<<
inline std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	return m.print(os);
}



//打印数组
std::ostream& Matrix::print(std::ostream& os) const
{
	int cnt = 0;
	int array_index = 0;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++, cnt++)
		{
			if (cnt && !(cnt % 4)) os << std::endl;
			os << _Matrix[x][y] << " ";
		}
	
	os << std::endl;
	return os;
}

//重写复合运算符+=
inline void Matrix::operator+=(const Matrix& m)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			_Matrix[x][y] += m._Matrix[x][y];
}

//重写操作符+,矩阵加法
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix swap(m1);
	swap += m2;
	return swap;
}

//重写操作符*,矩阵乘法
Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	int i = 0, j = 0, k = 0;
	Matrix swap;
	for (i; i < 4; i++)
	{
		for (j; j < 4; j++)
		{
			for (k; k < 4; k++)
				swap(i, j) += m1(i, k) * m2(k, j);
			k = 0;
		}
		j = 0;
	}
	return swap;
}