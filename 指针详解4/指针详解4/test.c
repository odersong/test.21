#include<stdio.h>
#include<string.h>

//strlen �� sizeof ��ӡ��Ҫ��%zd�Ų����о���

//��Ҫ�ʼǣ���sizeof��)�arr[i]��ʾ���ǵ�i���ַ������Σ�
//���Ƿ���arr[i]+1��arr[i]��ʾ��i���ĵ�ַ��arr[i]+1��ʾ��i������һ���ַ�1�����εĵ�ַ


//int main()
//{
//	//����������Ԫ�ص�ַ
//	//1. sizeof(������)-��������ʾ��������
//	//2. &������-��������ʾ��������
//	//��ַ�Ĵ�С����ָ��Ĵ�С4/8���ֽ�
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));      //16  sizeof(������)������������С��-��λ���ֽ�-16
//	printf("%d\n", sizeof(a+0));    //4/8 �����������ʾ������Ԫ�صĵ�ַ����Ԫ�ص�ַ��0������Ԫ�ص�ַ,��ַ�Ĵ�С����4/8���ֽ�
//	printf("%d\n", sizeof(*a));     //4   a����Ԫ�صĵ�ַ��*a��ʾ��Ԫ�ص�ֵ����4���ֽ�
//	printf("%d\n", sizeof(a+1));    //4/8 a��ʾ��Ԫ�صĵ�ַ��a+1��ʾ�ڶ����ֽڵĵ�ַ����4/8���ֽ�
//	printf("%d\n", sizeof(a[1]));   //4   a[1]��ʾ�ڶ���Ԫ�ص�ֵ����С��4���ֽ�
//	printf("%d\n", sizeof(&a));     //4/8 &a����������ĵ�ַ������ĵ�ַҲ�ǵ�ַ����С��4/8���ֽ�
//	printf("%d\n", sizeof(*&a));    //16  &a��ʾ����ĵ�ַ������ĵ�ַ�����÷��ʵ������飬sizeof�����������Ĵ�С16
//	printf("%d\n", sizeof(&a+1));   //4/8 &a������ĵ�ַ��&a+1�ǵ�ַ�����������飬�����ǵ�ַ 4/8
//	printf("%d\n", sizeof(&a[0]));  //4/8 a[0]��ʾ��Ԫ�أ�&a[0]����Ԫ�ص�ַ 4/8
//	printf("%d\n", sizeof(&a[0]+1));//4/8 &a[0]����Ԫ�ص�ַ &a[0]+1�ǵڶ���Ԫ�صĵ�ַ 4/8
//	return 0;
//}


//int main()
//{
//	char arr[] = { '1','5','6','8' };
//	printf("%s\n", arr);//���ֵ
//	printf("%d\n", strlen(arr));//���ֵ, strlen���ҵ�\0ֹͣ��������\0
//	printf("%d\n", sizeof(arr));//4��  sizeof�����ҵ�\0�����ǲ�������
//	return 0;
//}

//�ַ�����
//int main()
//{
//	char arr[] = { '0','4','9','7' };
//	printf("%d\n", sizeof(arr));        //4    sizeof�����������Ĵ�С4
//	printf("%d\n", sizeof(arr+0));      //4/8  arr����Ԫ�صĵ�ַ��arr+0������Ԫ�صĵ�ַ����С��4/8
//	printf("%d\n", sizeof(*arr));       //1    arr����Ԫ�ص�ַ��*arr����Ԫ�أ���С��1
//	printf("%d\n", sizeof(arr[1]));     //1    arr[1]�ǵڶ���Ԫ�ص�ֵ����С��1
//	printf("%d\n", sizeof(&arr));       //4/8  &arr������ĵ�ַ����С��4/8
//	printf("%d\n", sizeof(&arr+1));     //4/8  &arr+1��������������ĵ�ַ����С��4/8
//	printf("%d\n", sizeof(&arr[0]+1));  //4/8  &arr[0]+1����Ԫ�صĵ�ַ+1���ǵڶ���Ԫ�صĵ�ַ����С��4/8
//	return 0;
//}


//strlen�ǵ�\0��ֹͣ���Ҳ�����\0
//strlen�Ǵӵ�ַ������ҵ�\0�����ַ������ȵ�
//int main()
//{
//	char arr[] = { '4','6','7','9','1' };
//	printf("%d\n", strlen(arr));        //�Ҳ���\0���������ֵ
//	printf("%d\n", strlen(arr+0));      //arr+0�͵�һ��arr��һ���Ķ������ֵ -ע�⣬strlen����sizeof���arr���������ַ
//	//printf("%d\n", strlen(*arr));       //strlen�Ǵӵ�ַ�����ң�*arr����Ԫ�أ����Իᱨ��
//	//printf("%d\n", strlen(arr[1]));     //arr[1]�ǵڶ���Ԫ�أ����Իᱨ��
//	printf("%d\n", strlen(&arr));       //&arr�������ַ�������ֵ
//	printf("%d\n", strlen(&arr+1));     //&arr+1Ҳ�����ֵ�����Ǳ�&arrҪ��5�����ֵ����Ϊ&arr+1�����������ĵ�ַ�����Ա�&arr����5��Ԫ��
//	printf("%d\n", strlen(&arr[0]+1));  //&arr[0]+1����Ԫ�ؼ�һ��ʾ�ڶ���Ԫ�أ������ֵ���ӵڶ������������&arr��һ��Ԫ��
//	return 0;
//}


//��ַ�Ĵ�С����ָ��Ĵ�С����4/8
//int main()
//{
//	char arr[] = "abcde";
//	printf("%d\n", sizeof(arr));      //6,  arr�������ַ������Ԫ����abcde��\0
//	printf("%d\n", sizeof(arr+0));    //4/8 arr+0����Ԫ�ص�ַ����С��4/8
//	printf("%d\n", sizeof(*arr));     //1   *arr����Ԫ�أ���С��1	
//	printf("%d\n", sizeof(arr[1]));   //1   arr[1]�ǵڶ���Ԫ�أ���С��1
//	printf("%d\n", sizeof(&arr));     //4/8 &arr�������ַ����С��4/8	
//	printf("%d\n", sizeof(&arr+1));   //4/8 &arr+1��������������ĵ�ַ����С��4/8
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 &arr[0]+1����Ԫ��+1��ʾ�ڶ���Ԫ�صĵ�ַ����С��4/8
//	return 0;
//}


//��%zd��ӡ���ᱨ��
//strlen����\0��ֹͣ��ӡ��\0������  ���ַ�������
//int main()
//{
//	char arr[] = "abcde";
//	printf("%zd\n", strlen(arr));         //5   arr����Ԫ�ص�ַ���������\0��������\0����5��
//	printf("%zd\n", strlen(arr+0));       //5   arr+0Ҳ����Ԫ�ص�ַ
//	//printf("%zd\n", strlen(*arr));      //err ��Ϊstrlen�ǶԵ�ַ�������ģ�*arr����Ԫ�أ��������� �Ƿ�����
//                                        //ģ��ʵ��strlen����my_strlen(const char* str),����һ��ָ�룬���յ��ǵ�ַ	
//	//printf("%zd\n", strlen(arr[1]));    //err arr[1]�ǵڶ���Ԫ��Ҳ����
//	printf("%zd\n", strlen(&arr));         //5   &arr�������ַ ������5  
//                                        //����ĵ�ַ��Ҫ����ָ�����char(*p)[] = &arr;,����strlen���յ��ǵ�ַ�����������ַ,���о���  
//	printf("%zd\n", strlen(&arr+1));       //���ֵ   &arr+1����������ĵ�ַ�����������֪�������ʱ��\0���������ֵ
//	printf("%zd\n", strlen(&arr[0]+1));    //4   &arr[0]+1�Ǵӵڶ���Ԫ�ؿ�ʼ������������4
//	return 0;
//}




//int main()
//{
//	char* p = "abcde";//p���ĸ��ֽڷŲ���abcde�����Էŵ�������ĸ��ַ
//	printf("%zd\n", sizeof(p));//4/8  p��ָ�����,����ָ�����p�Ĵ�С��4
//	printf("%zd\n", sizeof(p+1));//4/8  p+1�õ������ַ�b�ĵ�ַ����С��4/8
//	printf("%zd\n", sizeof(*p));//1  *p�����ַ�����С��1
//	printf("%zd\n", sizeof(p[0]));//1 int arr[10];  arr[0]==*(arr+0)   p[0]==*(p+0)����Ԫ��
//	printf("%zd\n", sizeof(&p));//4/8  &p�ǵ�ַ����С��4/8
//	printf("%zd\n", sizeof(&p+1));//4/8  ��ַ����С��4/8
//	printf("%zd\n", sizeof(&p[0]+1));//4/8  ��ַ����С��4/8
//	return 0;
//}


//*��&�����໥����������&��*�����ԣ�Ҫ��˳��


//int main()
//{
//	char* p = "abcde";
//	printf("%zd\n", strlen(p));//5
//	printf("%zd\n", strlen(p+1));//4
//	//printf("%zd\n", strlen(*p));//err
//	//printf("%zd\n", strlen(p[0]));//err
//	printf("%zd\n", strlen(&p));//���ֵ  p��ָ�������&p��ȡ��p�ĵ�ַ����p�ĵ�ַ��ʼ�����ַ������������ֵ
//	printf("%zd\n", strlen(&p+1));//���ֵ
//	printf("%zd\n", strlen(&p[0]+1));//4
//	return 0;
//}


//��Ҫ�ʼǣ���sizeof��)�arr[i]��ʾ���ǵ�i���ַ������Σ�
//���Ƿ���arr[i]+1��arr[i]��ʾ��i���ĵ�ַ��arr[i]+1��ʾ��i������һ���ַ�1�����εĵ�ַ
//�ڶ�ά������Ҳ��һ����Ҫע�����arr[i]+1��ʾ�Ĳ��ǵ�i�м���һ�У����ǵ�i�����һλ�ĵ�ַ

//�ڶ�ά�����У�ÿһ�б�ʾһ��Ԫ��

//int main()
//{
//	int a[3][4] = { 0 };
//    printf("%zd\n", sizeof(a));//48  ��ʾ��������Ĵ�С��Ԫ����12����12*4=48
//	printf("%zd\n", sizeof(a[0][0]));//4  ��ʾ��һ��Ԫ�ش�С��4
//	printf("%zd\n", sizeof(a[0]));//16  a[0]��ʾa[0][i]��һ�����ĸ�Ԫ�أ�4*4=16
//	printf("%zd\n", sizeof(a[0]+1));//4/8  sizeof(a[0]+1)��ʾ��һ�еĵ�ַ���һλ���ǵ�ַ����С��4/8
//	printf("%zd\n", sizeof(*(a[0]+1)));//4
//	printf("%zd\n", sizeof(a+1));//4/8  a+1��ʾ�ڶ���һά����ĵ�ַ
//	printf("%zd\n", sizeof(*(a+1)));//16
//	printf("%zd\n", sizeof(&a[0]+1));//4/8  �����ʾȡ��һ���������ĵ�ַ�ټ�һ��ʾ�ڶ�������ĵ�ַ
//	printf("%zd\n", sizeof(*(&a[0]+1)));//4
//	printf("%zd\n", sizeof(*a));//16  �����ʾ��Ԫ�ص�ַ*���ǵ�һ�еĵ�ַ*����С��16
//	printf("%zd\n", sizeof(a[3]));//16  �����ʣ���������ʵ���㣬�������ͼ����Сa[3]��һ�����ĸ����ε�һά���� 16
//	return 0;
//}

//1.
//�ڶ�ά�����У�ÿһ�б�ʾһ��Ԫ�أ�ÿһ��Ԫ���ֱ�ʾһ������
//int main()
//{
//	int a[3][4];
//	printf("%p\n", &a[0][0]);//�׵�ַ�������׵�ַ��:28
//	printf("%p\n", a[0] + 1);//�����ʾ��һ���������һλ������ĵ�ַ��:2c  �����4
//	printf("%p\n", a + 1);//�����ʾ��һ��Ԫ�ؼ�һ�ǵڶ���Ԫ�أ��ǵڶ������飬����ĵ�ַ��:38  �����16
//	printf("%p\n", &a[0]+1);// �����ʾȡ��һ���������ĵ�ַ�ټ�һ��ʾ�ڶ�������ĵ�ַ      38
//	return 0;
//}

//2.
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//&a+1��Խ����������ĵ�ַ������&a+1Ҳ��ʾ��������ĵ�ַ��������������������ָ�����ͺ�ָ�����Ͳ�ƥ�䣬����Ҫ��ǿ��ת��
//	printf("%d %d\n", *(a + 1), *(ptr - 1));//ptr��ָ������ռ4/8���ֽڣ���һ����������һ��int��4���ֽڣ�ָ��5�ĵ�ַ��*��ptr-1����ʾ5
//	return 0;//����2 5
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
//	printf("%p\n", (unsigned long)p+0x1);//�����ת���������������ǵ�ַ�ˣ�������Ӿ���100001
//	printf("%p\n", (unsigned int*)p+0x1);//���ת�����޷�������ָ�룬P+1���Ǽ���һ�����εĲ���
//	printf("%p\n", (unsigned char*)p+0x1);//���ת�����޷����ַ���ָ�룬P+1���Ǽ���һ���ַ��͵Ĳ���
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
//	printf("%p\n", p+1);//�ӵ�����
//	return 0;
//}

//int main()
//{
//	char a = 'a';
//	char* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p + 1);//�ӵ���1
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
//	int* ptr = (int*)((int)a + 1);//����ǿ��ת�����׵�ַת�����������֣����ּ�һȻ��ǿ��ת���ɵ�ַ���ͱ�ʾ��ַ���ƫ��һ���ֽ�
//	printf("%p\n", ptr1);//���������ַ��58
//	printf("%p\n", ptr);//�����ַ����59
//	return 0;
//}


//4.
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr1 =(int *)(&a+1);
//	int *ptr2= (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//4,2000000   ����ָ����ڴ�ȡ���ĸ��ֽ�,������ַ�ָ���ȡ��һ���ֽ�
//	return 0;
//}

//5.
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//����������ڣ�������ű��ʽ�Ľ���Ǻ�һ��ֵ��1��3��5���ڶ�άָ�����һ����1��3���ڶ�����5��0����������0��0
//	int* p = a[0];//a[0]��ʾ��һ����Ԫ�صĵ�ַ���ѵ�һ�е�ַ������p
//	printf("%d\n", p[0]);//�����ʾ���ǵ�һ�еĵ�һ��Ԫ�أ������p[1]��ʾ��һ�еڶ���Ԫ��
//	return 0;//p���൱��һά����
//}


//int main()
//{
//	int a[3][2] = { {1,2},{5,6},{4,5} };
//	int* p = a[0];//a[0]��ʾ��һ�е��׵�ַ��1
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
//	p = a;//a��������int(*)[5]��p�����Ͳ�ͬ��p��������int(*)[4],����ֻ��ǿ�ƴ�4�н�ȥ
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
//	int* ptr2 = *(a + 1);//a+1��ʾ�ڶ�������ĵ�ַ���������Ϊ�����ڶ��е�ַ��*��ʾ�ҵ��ڶ��е�������׵�ַ
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}

//8.
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//at,pa++��ʾ����paָ��ĵ�ַ��������char*��char*++�õ��ڶ����ַ���
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
//	printf("%s\n", *pa+1);//ork�������ʾ����pa�����õ�w+1=o
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
//	printf("%s\n", *cpp[-2] + 3);//ST,����Ҫע�⣬��û���õ�++cpp����--cpp��cpp��ֵ����䣬����Ӱ������ļ���
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}


//                            ����������ص㣬һ��Ҫ��ϰ
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
//	printf("%d\n", *p);//5 ���*a�ҵ�1��+1��ʾint*ָ�����һ������
//	printf("%d\n", *p+1);//5 ���*a�ҵ�1��+1��ʾint*ָ�����4������
//	return 0;
//}



//��ϸ�������
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	printf("%p\n", pa);//pa�Ƕ���ָ��ָ��һ��ָ�룬�����һ��ָ��ĵ�ַ
//	printf("%p\n", pa+1);//pa+1��һ��ָ���4���ֽڵĵ�ַ��ָ��Ĳ�����4/8
//	printf("%p\n", *pa);//*pa���ҵ��˵�һ���ַ����ĵ�ַ
//	printf("%p\n", *pa + 1);//�ַ������׵�ַ��һ�����Ǽ�һ��char������ʾo�ĵ�ַ
//	printf("%s\n", *pa + 1);//ork
//	printf("%p\n", *(pa + 1));//*��pa+1����ʾ��һ��ָ������4/8���ֽڣ�����������ָ�룬*��ʾ�ҵ��ڶ����ַ������׵�ַ
//	return 0;
//}



//��ϸ�������
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
//	//printf("%p\n", *pp);//*pp��һ��ֵ�����ǵ�ַ
//	//printf("%c\n", *pp);//d
//	//printf("%p\n", *pp+1);//*pp�Ǹ�ֵ�����ǵ�ַ
//	//printf("%c\n", *pp+1);//e
//	printf("%p\n", *(pp+1));//*��ֵ�����ǵ�ַ
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


