main3 是最好的实现方法

同时读取与CPU占用率的解决方法就是select函数

main 阻塞读取，只能按顺序以此读取
main2 非阻塞读取 轮训的方式 能够同时读取 但是会造成CPU占用过高
main3 IO复用，采用select函数，能够同时读取并且不占用过多CPU


