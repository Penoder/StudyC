//
// Created by Penoder on 18-4-26.
//

#include <stdio.h>
#include "april26.h"

/**
 * 值发生改变，但是引用没有变化，所以后面打印引用的值，更新到最新的值
 */
void method() {
    int arr[] = {1, 2, 3, 4, 5};
    int *choice = arr;  // arr 是数组引用，保留的是第一个元素地址； 所以 *choice 是 1；
    printf("数组的引用和第一个元素的引用分别是： %p : %p  =====  第一个位置的值是： %i ;\n\n", arr, &arr[0], arr[0]);

    arr[0] = 2;     // 将第一个值改为 2； 值变了，但是引用还是之前的，所以 *choice 变成了 2；
    printf("数组的引用和第一个元素的引用分别是： %p : %p  =====  第一个位置的值是： %i ;\n\n", arr, &arr[0], arr[0]);

    printf("%p\n\n", choice);

    arr[1] = arr[2];    // 将第二个值改为 3；

    arr[2] = *choice;   // 将第三个值改为第一个值

    /**
     * sizeOf(arr) 表示整个数组所占空间
     * sizeOf(*arr) 表示第一个元素所占空间
     *
     * sizeOf(指针) 返回 4 或 8 分别表示 32位 和 64位操作系统的指针大小
     */
    printf("sizeOf(数组) 的大小： %i ； sizeOf(指针) 的大小： %i \n\n", (int) (sizeof(arr) / sizeof(*arr)), (int) sizeof(choice));

    printf("我选择的是： %i\n\n", arr[2]);

    /**
     * 字符数组可以直接通过 sizeOf(arrayName) 获取数组长度？
     * 原因在于一个字符占用一个字节，而上面 int 占用 4 个字节
     *
     * Java 中 char 2 字节， C char 1 字节
     *
     */
    char car[] = {"Everything will gonna be ok"};
    printf("%i ===== %i \n\n", (int) sizeof(car), (int) (sizeof(car) / sizeof(*car)));
}