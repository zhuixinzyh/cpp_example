#include <iostream>

using namespace std;
// 函数指针结构体
typedef struct _OP
{
	float (*p_add)(float a, float b);
	float (*p_div)(float a, float b);
	float (*p_mul)(float a, float b);
	float (*p_sub)(float a, float b);
} OP; // 使用typedef 来进行重命名结构体类型为OP

/****************************************
 * 加减乘除函数
 ***************************************/
float ADD(float a, float b)
{
	return a + b;
}

float SUB(float a, float b)
{
	return a - b;
}

float MUL(float a, float b)
{
	return a * b;
}

float DIV(float a, float b)
{
	return a / b;
}
// //初始化指针函数
// void op_init(OP *op)
// {
// 	op->p_add = ADD;
// 	op->p_sub = SUB;
// 	op->p_mul = MUL;
// 	op->p_div = DIV;
// }
// 实例化OP//对实例化OP进行初始化
OP op1 = {
	.p_add = ADD,
	.p_div = DIV,
	.p_mul = MUL,
	.p_sub = SUB};

float add_mul_div_sub(float a, float b, float (*p_func)(float, float))
{
	return p_func(a, b);
}
int main(int argc, char *argv)
{
	cout << "main go" << endl;
	cout << "inst op operation" << endl;
	cout << "main add: " << add_mul_div_sub(1, 2, op1.p_add) << endl;
	cout << "main sub: " << add_mul_div_sub(1, 2, op1.p_sub) << endl;
	cout << "main mul: " << add_mul_div_sub(1, 2, op1.p_mul) << endl;
	cout << "main div: " << add_mul_div_sub(1, 2, op1.p_div) << endl;
	cout << "main done" << endl;
	return 0;
}