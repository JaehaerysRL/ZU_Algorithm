// 9-3 Dynamic Array (10分)
//编写一个能动态增长的存放int型数据的数组的库，数组用以下的数据类型表示：
//typedef struct {
//    int *content;
//    int size;
//} Array;
 
//这个库要提供以下API函数：

//Array array_create();
//void array_free(Array* array);

//int array_size(const Array *array);
//void array_inflate(Array *array);

//int array_get(const Array *array, int index);
//void array_set(Array *array, int index, int value);

//Array array_clone(const Array *array);
  
//array_create()返回一个新创建的Array，其中的size为宏BLOCK_SIZE所定义，这个宏由Makefile给出，在程序中可以直接使用。
//array_free()释放Array中的存储空间，并置content和size为0。
//array_size()返回Array的size。
//array_inflate()使得Array增大BLOCK_SIZE个大小。
//array_get()返回在index位置上的int值，index从0开始。
//array_set()将index位置上的值置为value，index从0开始。
//array_clone()复制一个新的Array，其内容与函数参数相同。
//你的提交应该在src下有array.h和array.c两个文件。
//在本地测试时，如果使用Windows，可以用mingw32-make来执行Makefile完成编译，编译产生的是test.exe，用命令行执行时，必须加命令行参数来指定输出测试结果的文件名，如：test 123.txt

#include<stdio.h>
#include <stdlib.h>
#include "array.h"

Array array_create() {
    Array array;
    array.size = BLOCK_SIZE;
    int* num = (int*)malloc(sizeof(int)* array.size);
    array.content = num;
    return array;
}
int array_size(const Array* array) {
    return array->size;
}

void array_set(Array* array, int index, int value) {
    array->content[index] = value;
}

int array_get(const Array* array, int index) {
    return array->content[index];
}

void array_inflate(Array* array) {
	int* newNum = (int*)malloc(sizeof(int) * (BLOCK_SIZE+ array->size));
	array->size += BLOCK_SIZE;
	for (int i = 0; i < BLOCK_SIZE; i++)
    {
        newNum[i] = array->content[i];
        newNum[i + BLOCK_SIZE] = array->content[i];
    }
	free(array->content);
    array->content = newNum;
}

Array array_clone(const Array* array) {
    Array newArray;
    newArray.size = array->size;
    int* newNum = (int*)malloc(sizeof(int) * array->size);
    for (int i = 0; i < array->size; i++)
    {
        newNum[i] = array->content[i];
    }
    newArray.content = newNum;
    return newArray;
}

void array_free(Array* array) {
    free(array->content);
    array->content = NULL;
    array->size = 0;
}