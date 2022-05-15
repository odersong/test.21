#include<stdio.h>
#include<string.h>

//strlen 和 sizeof 打印都要用%zd才不会有警告

//重要笔记：在sizeof（)里，arr[i]表示的是第i个字符或整形，
//但是放入arr[i]+1，arr[i]表示第i个的地址，arr[i]+1表示第i个后面一个字符1或整形的地址


//int main()
//{
//	//数组名是首元素地址
//	//1. sizeof(数组名)-数组名表示整个数组
//	//2. &数组名-数组名表示整个数组
//	//地址的大小就是指针的大小4/8个字节
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));      //16  sizeof(数组名)计算的是数组大小，-单位是字节-16
//	printf("%d\n", sizeof(a+0));    //4/8 数组名这里表示的是首元素的地址，首元素地址加0还是首元素地址,地址的大小就是4/8个字节
//	printf("%d\n", sizeof(*a));     //4   a是首元素的地址，*a表示首元素的值，是4个字节
//	printf("%d\n", sizeof(a+1));    //4/8 a表示首元素的地址，a+1表示第二个字节的地址，是4/8个字节
//	printf("%d\n", sizeof(a[1]));   //4   a[1]表示第二个元素的值，大小是4个字节
//	printf("%d\n", sizeof(&a));     //4/8 &a是整个数组的地址，数组的地址也是地址，大小是4/8个字节
//	printf("%d\n", sizeof(*&a));    //16  &a表示数组的地址，数组的地址解引用访问的是数组，sizeof计算的是数组的大小16
//	printf("%d\n", sizeof(&a+1));   //4/8 &a是数组的地址，&a+1是地址跳过整个数组，但还是地址 4/8
//	printf("%d\n", sizeof(&a[0]));  //4/8 a[0]表示首元素，&a[0]是首元素地址 4/8
//	printf("%d\n", sizeof(&a[0]+1));//4/8 &a[0]是首元素地址 &a[0]+1是第二个元素的地址 4/8
//	return 0;
//}


//int main()
//{
//	char arr[] = { '1','5','6','8' };
//	printf("%s\n", arr);//随机值
//	printf("%d\n", strlen(arr));//随机值, strlen是找到\0停止，不包括\0
//	printf("%d\n", sizeof(arr));//4个  sizeof不是找到\0，而是参数多少
//	return 0;
//}

//字符数组
//int main()
//{
//	char arr[] = { '0','4','9','7' };
//	printf("%d\n", sizeof(arr));        //4    sizeof计算的是数组的大小4
//	printf("%d\n", sizeof(arr+0));      //4/8  arr是首元素的地址，arr+0还是首元素的地址，大小是4/8
//	printf("%d\n", sizeof(*arr));       //1    arr是首元素地址，*arr是首元素，大小是1
//	printf("%d\n", sizeof(arr[1]));     //1    arr[1]是第二个元素的值，大小是1
//	printf("%d\n", sizeof(&arr));       //4/8  &arr是数组的地址，大小是4/8
//	printf("%d\n", sizeof(&arr+1));     //4/8  &arr+1是跳过整个数组的地址，大小是4/8
//	printf("%d\n", sizeof(&arr[0]+1));  //4/8  &arr[0]+1是首元素的地址+1，是第二个元素的地址，大小是4/8
//	return 0;
//}


//strlen是到\0才停止，且不计算\0
//strlen是从地址中向后找到\0计算字符串长度的
//int main()
//{
//	char arr[] = { '4','6','7','9','1' };
//	printf("%d\n", strlen(arr));        //找不到\0所以是随机值
//	printf("%d\n", strlen(arr+0));      //arr+0和第一个arr是一样的都是随机值 -注意，strlen不是sizeof里的arr不是数组地址
//	//printf("%d\n", strlen(*arr));       //strlen是从地址向下找，*arr是首元素，所以会报错
//	//printf("%d\n", strlen(arr[1]));     //arr[1]是第二个元素，所以会报错
//	printf("%d\n", strlen(&arr));       //&arr是数组地址，是随机值
//	printf("%d\n", strlen(&arr+1));     //&arr+1也是随机值，但是比&arr要少5个随机值，因为&arr+1，是数组后面的地址，所以比&arr少了5个元素
//	printf("%d\n", strlen(&arr[0]+1));  //&arr[0]+1是首元素加一表示第二个元素，是随机值，从第二个向后数，比&arr少一个元素
//	return 0;
//}


//地址的大小就是指针的大小都是4/8
//int main()
//{
//	char arr[] = "abcde";
//	printf("%d\n", sizeof(arr));      //6,  arr是数组地址，数组元素有abcde和\0
//	printf("%d\n", sizeof(arr+0));    //4/8 arr+0是首元素地址，大小是4/8
//	printf("%d\n", sizeof(*arr));     //1   *arr是首元素，大小是1	
//	printf("%d\n", sizeof(arr[1]));   //1   arr[1]是第二个元素，大小是1
//	printf("%d\n", sizeof(&arr));     //4/8 &arr是数组地址，大小是4/8	
//	printf("%d\n", sizeof(&arr+1));   //4/8 &arr+1是跳过整个数组的地址，大小是4/8
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 &arr[0]+1是首元素+1表示第二个元素的地址，大小是4/8
//	return 0;
//}


//用%zd打印不会报错
//strlen遇到\0才停止打印，\0不计数  。字符串长度
//int main()
//{
//	char arr[] = "abcde";
//	printf("%zd\n", strlen(arr));         //5   arr是首元素地址，向后数到\0，不计入\0，是5个
//	printf("%zd\n", strlen(arr+0));       //5   arr+0也是首元素地址
//	//printf("%zd\n", strlen(*arr));      //err 因为strlen是对地址向后计数的，*arr是首元素，所及报错 非法访问
//                                        //模拟实现strlen就是my_strlen(const char* str),这是一个指针，接收的是地址	
//	//printf("%zd\n", strlen(arr[1]));    //err arr[1]是第二个元素也报错
//	printf("%zd\n", strlen(&arr));         //5   &arr是数组地址 所以是5  
//                                        //数组的地址需要数组指针接收char(*p)[] = &arr;,但是strlen接收的是地址，不是数组地址,会有警告  
//	printf("%zd\n", strlen(&arr+1));       //随机值   &arr+1是跳过数组的地址，跳过数组后不知道后面何时有\0所以是随机值
//	printf("%zd\n", strlen(&arr[0]+1));    //4   &arr[0]+1是从第二个元素开始计数，所以是4
//	return 0;
//}




//int main()
//{
//	char* p = "abcde";//p有四个字节放不了abcde，所以放的是首字母地址
//	printf("%zd\n", sizeof(p));//4/8  p是指针变量,计算指针变量p的大小是4
//	printf("%zd\n", sizeof(p+1));//4/8  p+1得到的是字符b的地址，大小是4/8
//	printf("%zd\n", sizeof(*p));//1  *p是首字符，大小是1
//	printf("%zd\n", sizeof(p[0]));//1 int arr[10];  arr[0]==*(arr+0)   p[0]==*(p+0)是首元素
//	printf("%zd\n", sizeof(&p));//4/8  &p是地址，大小是4/8
//	printf("%zd\n", sizeof(&p+1));//4/8  地址，大小是4/8
//	printf("%zd\n", sizeof(&p[0]+1));//4/8  地址，大小是4/8
//	return 0;
//}


//*和&可以相互抵消，但是&和*不可以，要按顺序


//int main()
//{
//	char* p = "abcde";
//	printf("%zd\n", strlen(p));//5
//	printf("%zd\n", strlen(p+1));//4
//	//printf("%zd\n", strlen(*p));//err
//	//printf("%zd\n", strlen(p[0]));//err
//	printf("%zd\n", strlen(&p));//随机值  p是指针变量，&p是取出p的地址，从p的地址开始计算字符数量，是随机值
//	printf("%zd\n", strlen(&p+1));//随机值
//	printf("%zd\n", strlen(&p[0]+1));//4
//	return 0;
//}


//重要笔记：在sizeof（)里，arr[i]表示的是第i个字符或整形，
//但是放入arr[i]+1，arr[i]表示第i个的地址，arr[i]+1表示第i个后面一个字符1或整形的地址
//在二维数组中也是一样，要注意的是arr[i]+1表示的不是第i行加了一行，而是第i行向后一位的地址

//在二维数组中，每一行表示一个元素

//int main()
//{
//	int a[3][4] = { 0 };
//    printf("%zd\n", sizeof(a));//48  表示整个数组的大小，元素有12个，12*4=48
//	printf("%zd\n", sizeof(a[0][0]));//4  表示第一个元素大小是4
//	printf("%zd\n", sizeof(a[0]));//16  a[0]表示a[0][i]第一行有四个元素，4*4=16
//	printf("%zd\n", sizeof(a[0]+1));//4/8  sizeof(a[0]+1)表示第一行的地址向后一位，是地址，大小是4/8
//	printf("%zd\n", sizeof(*(a[0]+1)));//4
//	printf("%zd\n", sizeof(a+1));//4/8  a+1表示第二行一维数组的地址
//	printf("%zd\n", sizeof(*(a+1)));//16
//	printf("%zd\n", sizeof(&a[0]+1));//4/8  这个表示取第一行数组名的地址再加一表示第二行数组的地址
//	printf("%zd\n", sizeof(*(&a[0]+1)));//4
//	printf("%zd\n", sizeof(*a));//16  这个表示首元素地址*，是第一行的地址*，大小是16
//	printf("%zd\n", sizeof(a[3]));//16  不访问，不参与真实计算，是用类型计算大小a[3]是一个有四个整形的一维数组 16
//	return 0;
//}

//1.
//在二维数组中，每一行表示一个元素，每一个元素又表示一个数组
//int main()
//{
//	int a[3][4];
//	printf("%p\n", &a[0][0]);//首地址，例如首地址是:28
//	printf("%p\n", a[0] + 1);//这个表示第一行数组向后一位，这个的地址是:2c  这个加4
//	printf("%p\n", a + 1);//这个表示第一个元素加一是第二个元素，是第二个数组，这个的地址是:38  这个加16
//	printf("%p\n", &a[0]+1);// 这个表示取第一行数组名的地址再加一表示第二行数组的地址      38
//	return 0;
//}

//2.
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//&a+1是越过整个数组的地址，但是&a+1也表示的是数组的地址，所以他的类型是数组指针类型和指针类型不匹配，所以要加强制转换
//	printf("%d %d\n", *(a + 1), *(ptr - 1));//ptr是指针类型占4/8个字节，减一就是向左移一个int型4个字节，指向5的地址，*（ptr-1）表示5
//	return 0;//答案是2 5
//}

//3.
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
//int main()
//{
//	printf("%zd\n", sizeof(struct Test));
//	p =(struct Test*)0x100000;
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p+0x1);//这个是转换成了整数，不是地址了，整数相加就是100001
//	printf("%p\n", (unsigned int*)p+0x1);//这个转换成无符号整形指针，P+1就是加了一个整形的步长
//	printf("%p\n", (unsigned char*)p+0x1);//这个转换成无符号字符型指针，P+1就是加了一个字符型的步长
//	return 0;
//}

//int main()
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//	printf("%zd\n", sizeof(Num));
//	printf("%zd\n", sizeof(pcName));
//	printf("%zd\n", sizeof(sDate));
//	printf("%zd\n", sizeof(cha));
//	printf("%zd\n", sizeof(sBa));
//}


//int main()
//{
//	int a = 1;
//	int* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p+1);//加的是四
//	return 0;
//}

//int main()
//{
//	char a = 'a';
//	char* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p + 1);//加的是1
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*) (&a + 1);
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)((int)a);
//	int* ptr = (int*)((int)a + 1);//这里强制转换将首地址转换成整型数字，数字加一然后强制转换成地址，就表示地址向后偏移一个字节
//	printf("%p\n", ptr1);//比如这个地址是58
//	printf("%p\n", ptr);//这个地址就是59
//	return 0;
//}


//4.
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr1 =(int *)(&a+1);
//	int *ptr2= (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//4,2000000   整型指针从内存取出四个字节,如果是字符指针就取出一个字节
//	return 0;
//}

//5.
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//里面的数字在（）里，逗号表达式的结果是后一个值：1，3，5，在二维指针里第一行是1，3，第二行是5，0，第三行是0，0
//	int* p = a[0];//a[0]表示第一行首元素的地址，把第一行地址传给了p
//	printf("%d\n", p[0]);//这个表示的是第一行的第一个元素，如果是p[1]表示第一行第二个元素
//	return 0;//p就相当于一维数组
//}


//int main()
//{
//	int a[3][2] = { {1,2},{5,6},{4,5} };
//	int* p = a[0];//a[0]表示第一行的首地址是1
//	printf("%d\n", p[0]);
//	return 0;
//}


//int main()
//{
//	int a[2][2] = { {2,5},{4,6} };
//	int* p = a[1];
//	printf("%d\n", p[0]);
//	return 0;
//}

//6.
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//a的类型是int(*)[5]和p的类型不同，p的类型是int(*)[4],五列只能强制存4列进去
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);
//	return 0;
//}

//7.
//int main()
//{
//	int a[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int *ptr1 = (int *)(&a + 1);
//	int* ptr2 = *(a + 1);//a+1表示第二行数组的地址，可以理解为整个第二行地址，*表示找到第二行的数组的首地址
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}

//8.
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//at,pa++表示的是pa指向的地址的类型是char*，char*++得到第二个字符串
//	return 0;
//}

//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(int*));
//	return 0;
//}

//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	printf("%s\n", *pa);//work
//	printf("%s\n", *pa+1);//ork，这个表示的是pa皆引得到w+1=o
//	return 0;
//}

//9.
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST,这里要注意，并没有用到++cpp或者--cpp，cpp的值不会变，不会影响下面的计算
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}


//                            下面分析是重点，一定要复习
//int main()
//{
//	int a[] = { 1,6,7,9,5 };
//	int* p = a;
//	printf("%d\n", *a + 1);//2
//	return 0;
//}

//int main()
//{
//	int* a[] = { 1,4,8,9 };
//	int** p = a;
//	printf("%d\n", *p);//5 这个*a找到1，+1表示int*指针向后一个步长
//	printf("%d\n", *p+1);//5 这个*a找到1，+1表示int*指针向后4个步长
//	return 0;
//}



//仔细看下面的
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	printf("%p\n", pa);//pa是二级指针指向一级指针，存的是一级指针的地址
//	printf("%p\n", pa+1);//pa+1是一级指针加4个字节的地址，指针的步长是4/8
//	printf("%p\n", *pa);//*pa是找到了第一个字符串的地址
//	printf("%p\n", *pa + 1);//字符串的首地址加一，就是加一个char步长表示o的地址
//	printf("%s\n", *pa + 1);//ork
//	printf("%p\n", *(pa + 1));//*（pa+1）表示加一个指针类型4/8个字节，数组有三个指针，*表示找到第二个字符串的首地址
//	return 0;
//}



//仔细看下面的
//int main()
//{
//	char a[] = "dawihf";
//	char* p = a;
//	//printf("%s\n", p);
//	char* *pp = p;
//	//printf("%p\n", pp);//
//	//printf("%s\n", pp);//dawihf
//	//printf("%p\n", pp+1);//
//	//printf("%s\n", pp+1);//hf
//	//printf("%p\n", *pp);//*pp是一个值，不是地址
//	//printf("%c\n", *pp);//d
//	//printf("%p\n", *pp+1);//*pp是个值，不是地址
//	//printf("%c\n", *pp+1);//e
//	printf("%p\n", *(pp+1));//*是值，不是地址
//	printf("%c\n", *(pp+1));//h
//	return 0;
//}


//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	printf("%s\n", *(pa + 1));//at
//	return 0;
//}

//int main()
//{
//	char a[] = "abcde";
//	char* p = a;
//	printf("%c\n", *p + 1);
//	return 0;
//}


//int main()
//{
//	short a[] = { 1,5,8,9,7 };
//	short* p = a;
//	printf("%p\n", p);
//	printf("%p\n", (p+1));
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,5,8,9,7 };
//	int* p = a;
//	printf("%p\n", p);
//	printf("%p\n", (p + 1));
//	return 0;
//}


//int main()
//{
//	int* a[] = { 1,2,5,7,8,9 };
//	int** p = a;
//	printf("%d\n", *p + 1);
//	return 0;
//}


