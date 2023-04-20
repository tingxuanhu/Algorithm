# Tips：
## 动态规划用到数组
- 在面对动态规划需要dp数组的时候，C++语言层面更推荐使用int* dp = new int[N] ();还是int dp[N] = {0};
  - 在面对动态规划需要dp数组的时候，C++语言层面更推荐使用第二种方式：int dp[N] = {0}; 进行静态数组的定义和初始化。原因如下：
    - 直观性更强：静态数组定义和初始化时使用花括号语法，更直观易懂，不需要过多的解释和注释。
    - 代码简洁：不需要显式地使用new关键字进行内存动态分配，代码更加简洁明了。
    - 更高效：在动态规划问题中，通常需要频繁地访问dp数组，使用静态数组可以减少内存动态分配和释放的开销，从而提高效率。
    - 可读性更好：静态数组在代码中更易于理解和阅读，不需要考虑内存释放和管理等问题，提高了代码的可读性和可维护性。

- int* dp = new int[n + 1][k + 1] (); // 初始化为0
- int* dp = new int[n + 1][k + 1]{-1};   // 初始化为-1

## 常用的输入输出流总结：
- `cin >>` 负责吃string，碰到空格、回车、制表符则停止，缓存空间暂时保留下来，直到被使用或者再次吃新的数据
  - 因此不能用cin来吃整行以空格为分隔的输入，否则会面临只能吃到第一个数据，后续所有数据作废的尴尬局面
- std::isstringstream可以解决cin吃不了整行按空格分隔的输入的bug：
- 但其实更推荐使用的是scanf函数，比较轻松快捷，而且题目输入一般不会有误，无需判断，这能够省下不少写代码的时间
```cpp
int parentVal, leftVal, rightVal;
while (scanf("%d:%d|%d", &parentVal, &leftVal, &rightVal) == 3) {...}
```cpp
如果想要在输入中使用空格或其他分隔符来分隔整数值，可以使用 `getline()` 函数读取一行字符串，然后使用 `istringstream` 类型的输入流来逐个读取其中的整数值。
对于输入描述中的示例输入，可以按照以下方式读取：
int main() {
    string line;
    getline(cin, line);  // 读取第一行输入的链表A的值
    istringstream iss(line);  // 将字符串转换成输入流
    int val;
    while (iss >> val) {  // 从输入流中读取整数
        cout << val << " ";
    }
    cout << endl;

    line.clear();
    getline(cin, line);  // 读取第二行输入的链表B的值
    iss.str(line);  // 清除 istringstream 对象之前的输入流，并将其替换为新字符串转换成的输入流
    iss.clear();   // iss.str(line) 将字符串 line 转成新输入流，并替换掉 istringstream 对象之前的输入流，但不会清除 istringstream 对象的状态和缓冲区，因此在使用 iss.str(line) 函数之前，需要先调用 iss.clear() 函数清除 istringstream 对象的状态和缓冲区。
    while (iss >> val) { 
        cout << val << " ";
    }
    cout << endl;

    return 0;
 在上述代码中，首先使用 `getline(cin, line)` 读取第一行输入的整数值，并将字符串转换成输入流 `istringstream`，然后逐个读取其中的整数值并输出。
 接着使用 `getline(cin, line)` 读取第二行输入的整数值，再将字符串转换成输入流 `istringstream`，并逐个读取其中的整数值并输出。
}




```

